#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ax, bx, cx;

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
    int n, l;
    
    vector<Edge> v;
    
    cin >> n >> l;
    if (n < 1 || n > 1000){
        return 0;
    }
    if (l < 1 || l > 100000){
        return 0;
    }
    
    for(int i=0;i<l;i++){
        cin >> ax >> bx >>cx;
        
        if (cx < 1 || cx > 10000){
            return 0;
        }
        
        v.push_back(Edge(ax,bx,cx));
    }
    
    sort(v.begin(),v.end());
    int set[n];
    
    for(int i=0;i<n;i++){
        set[i]=i;
    }
    int sum=0;
    
    for(int i=0; i<v.size();i++){
        if(!findParent(set,v[i].node[0]-1,v[i].node[1]-1)){
            sum+=v[i].d;
            unionParent(set,v[i].node[0]-1,v[i].node[1]-1);
        }
    }
    cout << sum;
    return 0;
}

