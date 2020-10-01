#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getParent(int parent[], int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x]=getParent(parent, parent[x]);
    }
}

void unionParent(int parent[], int a, int b){
    a=getParent(parent, a);
    b=getParent(parent, b);
    if(a<b){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}

bool findParent(int parent[], int a, int b){
    a=getParent(parent, a);
    b=getParent(parent, b);
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}

class Edge{
public :
    int node[2];
    int d;
    Edge(int a, int b, int d){
        this->node[0]=a;
        this->node[1]=b;
        this->d=d;
    }
    bool operator <(const Edge &e)const{
        return this-> d < e.d;
    }
};

int main(){
    vector<Edge> v;
    while(true){
        int ax, bx, cx=0;
        int n, l;
    
        cin >> n >> l;
        if(n==0&&l==0){
            break;
        }
        if (n < 1 || n > 200000||l < n-1 || l > 2000000){
            return 0;
        }

        for(int i=0;i<l;i++){
            cin >> ax >> bx >>cx;
            v.push_back(Edge(ax,bx,cx));
        }
        sort(v.begin(),v.end());

        int set[n];
        for(int i=0;i<=n;i++){
            set[i]=i;
        }
        
        int money=0;
        for(int i=0; i<v.size(); i++){
            money+=v[i].d;
        }
        
        for(int i=0; i<v.size(); i++){
        if(!findParent(set,v[i].node[0],v[i].node[1])){
            unionParent(set,v[i].node[0],v[i].node[1]);
            money-=v[i].d;
            }
        }
        cout << money << endl;
        v.clear();
    }
    return 0;
}
