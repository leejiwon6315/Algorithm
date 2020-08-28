#include<iostream>
#include<queue>
#include<vector>
#define max 100+1
using namespace std;

bool c[max];
vector<int> arr[max];
int d[max];

void bfs(int start){
    queue<int> q;
    q.push(start);
    c[start]=true;
    
    while(!q.empty()){
        int now =q.front();
        q.pop();

        for(int i=0;i<arr[now].size();i++){
            int y=arr[now][i];
            if(!c[y] && arr[now][i]){
                c[y]=true;
                d[y]=d[now]+1;
                q.push(y);
            }
        }
    }
}

int main(){
    int n, m;
    int k1, k2;
    int a, b;
    
    cin >> n ;
    cin >> k1 >> k2 ;
    cin >> m ;
    
    for(int i=0; i<m; i++){
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
    }
    
    bfs(k1);
    
    if(d[k2]!=0){
        cout << d[k2] ;
    }
    else{
        cout << "-1" ;
    }

    return 0;
}

