#include <iostream>
#include <string>

using namespace std;

class Node{
    Node* link;     //다음노드
    Node* prevLink;    //이전노드

public:
    int chaSoo;
    int kyeSoo;
    
    Node( int kye=0, int cha=0)
        : chaSoo(cha), kyeSoo(kye) , link(NULL), prevLink(NULL) {}
    
    
    Node* getLink(){
        return link;
    }
    
    void setLink( Node *n ){
        link = n;
    }
    
    Node* getPrevLink(){
        return prevLink;
    }
    
    void setPrevLink( Node *b ){
        prevLink = b;
    }
    
    void insertNext(Node* n){
        if(n!=NULL){
            n->prevLink = this;
            n->link = link;
            
            if(link != NULL) link->prevLink = n;
            link = n;
        }
    }
    
    void display(){
        cout << kyeSoo << "x^" << chaSoo << " ";
    }
};

class LinkedList{
    Node org;
    
    public:
    LinkedList(): org(0){}
    
    ~LinkedList(){
        
    }
    
    Node* getHead(){
        return org.getLink();
    }
    
    bool isEmpty(){
        return getHead() == NULL;
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
    
    int Size(){
        int cnt = 0;
        for(Node* p=getHead(); p!=NULL;p=p->getLink()){
            cnt ++;
        }
        return cnt;
    }
    
};

void Poly_Print(LinkedList Array){
    Node* p=Array.getEntry(Array.Size()-1);
    
    while(p!=Array.getEntry(0)){
        p->display();
        p=p->getPrevLink();
    }
    p->display();
}

LinkedList Poly_Add(LinkedList a, LinkedList b, LinkedList c){
    int maxSize = a.Size()>b.Size() ? a.Size() : b.Size();
    
    int i=1, j=1;
    
    while(maxSize--){
    
        Node* aNode = a.getEntry(a.Size()-i);
        Node* bNode = b.getEntry(b.Size()-j);
        
        int newChaOfA = aNode->chaSoo, newKyeOfA = aNode->kyeSoo;
        int newChaOfB = bNode->chaSoo, newKyeOfB = bNode->kyeSoo;
    
        if(newChaOfA == newChaOfB){
            c.insert(0, new Node(newKyeOfA + newKyeOfB, newChaOfB));
            i++;
            j++;
        }
        else if(newChaOfA > newChaOfB){
            c.insert(0, new Node(newKyeOfA, newChaOfA));
            i++;
        }
        else{
            c.insert(0, new Node(newKyeOfB, newChaOfB));
            j++;
        }
    }
    return c;
}

int main(){
    
    int a, b;
    LinkedList arr1, arr2, arr3, answer;
    
    cout << "다항식 A를 입력하세요\n";
    
    while(1){
        cin >> a >> b;
        if(b>=0){
            arr1.insert(0, new Node(a, b));
        }
        else break;
    }
    cout << "A= ";
    Poly_Print(arr1);
    
    cout << "\n\n다항식 B를 입력하세요\n";
    
    while(1){
        cin >> a >> b;
        if(b>=0){
            arr2.insert(0, new Node(a, b));
        }
        else break;
    }
    cout << "B= ";
    Poly_Print(arr2);
    
    arr3 = Poly_Add(arr1, arr2, arr3);
    
    cout << "\n\nC= ";
    Poly_Print(arr3);
    
    Node* lastAnswer = arr3.getEntry(arr3.Size()-1);
    
    cout <<"\n\nC의 최고차수는 " << lastAnswer->chaSoo << "이고, 그 항의 계수는 " << lastAnswer->kyeSoo << "이다. \n";
    
    return 0;
}
