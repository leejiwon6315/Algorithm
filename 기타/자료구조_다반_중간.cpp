#include<iostream>
#include<cstdio>

using namespace std;

class Node{
    Node* link;
    int data;

public:
    Node( int val=0)
        : data(val), link(NULL) {}


    Node* getLink(){    // link가 private로 선언되어 있어 접근하기 위해 get으로 link를 가져옴
        return link;
    }

    void setLink( Node *next ){    // 외부에서 link에 접근
        link = next;
    }

    char display(){
        return data;
    }

    bool hasData(int val){
        return data == val;
    }

    void insertNext(Node* n){
        if(n!=NULL){
            n->link = link;
            link = n;
        }
    }

    Node* removeNext(){
        Node* removed = link;

        if(removed != NULL){
            link = removed->link;
        }

        return removed;
    }
};

class LinkedList{
    Node org;

    public:
    LinkedList(): org(0){}

    ~LinkedList(){
        clear();
    }

    void clear(){
        while(!isEmpty())
            delete remove(0);
    }

    Node* getHead(){
        return org.getLink();
    }

    bool isEmpty(){
        return getHead() == NULL;
    }
    
    int Size(){
        int cnt = 0;
        for(Node* p=getHead(); p!=NULL;p=p->getLink()){
            cnt ++;
        }
        return cnt;
    }

    Node* getEntry(int pos){
        Node* n = &org;
        for(int i=-1; i<pos; i++, n=n->getLink()){
            if(n==NULL) break;
        }
        return n;
    }
    
    void insert(int pos, Node* n){
        Node* prev = getEntry(pos-1);
    
        if(prev != NULL){
            prev -> insertNext(n);
        }
    }

    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev -> removeNext();
    }

    Node* find(int val){
        for(Node* p = getHead(); p!=NULL; p=p->getLink()){
            if(p->hasData(val)) return p;
        }
        return NULL;
    }

};

class Deque: public LinkedList{
    public:
        void insertFront(Node *n){ insert(0,n);}
        Node* deleteFront() {return remove(0);}
        Node* peekFront(){return getEntry(0);}
        void insertRear(Node* n){insert(Size(), n);}
        Node* deleteRear(){return remove(Size()-1);}
        Node* peekRear(){return getEntry(Size()-1);}
        int DequeSize(){return Size();}
    
};

int main(){

    Deque deq;
    char A='A', B='B', C='C',D='D',E='E',F='F';

    deq.insertFront(new Node(A));
    cout << "Front 삽입 A >> DeQue : [ ";
    cout << deq.peekFront()->display() <<" ]\n";
    
    deq.insertFront(new Node(B));
    cout << "Front 삽입 B >> DeQue : [ ";
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() <<" ]\n";
    
    deq.insertRear(new Node(C));
    cout << "Rear 삽입 C >> DeQue : [ ";
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() << " " <<deq.getEntry(2)->display() <<" ]\n";
    
    cout << "Size of Deque = " <<deq.DequeSize()<< "\n";
    
    deq.deleteFront();
    cout << "Front 삭제 >> DeQue : [ ";
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() <<" ]\n";
    
    deq.deleteRear();
    cout << "Rear 삭제 >> DeQue : [ ";
    cout << deq.peekFront()->display()<<" ]\n";
    
    deq.insertRear(new Node(D));
    cout << "Rear 삽입 D >> DeQue : [ ";
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() <<" ]\n";
    
    deq.insertFront(new Node(E));
    cout << "Front 삽입 E >> DeQue : [ ";
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() << " " <<deq.getEntry(2)->display() <<" ]\n";
    
    cout << "Front 삽입 F >> DeQue : [ ";
    deq.insertFront(new Node(F));
    cout << deq.peekFront()->display()<< " " <<deq.getEntry(1)->display() << " " <<deq.getEntry(2)->display()<< " " <<deq.getEntry(3)->display() <<" ]\n";
    
    cout << "Size of Deque = " << deq.DequeSize()<< "\n";
    cout << "peek Front item : " << deq.peekFront()->display() << "\n";
    cout << "peek Rear item : " << deq.peekRear()->display() << endl;
    

    return 0;
}
