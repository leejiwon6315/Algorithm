#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define max 1001

using namespace std;
vector<int> arr[max];
bool visit[max];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i=0; i<arr[x].size(); i++){
            int y = arr[x][i];
            if(!visit[y]){
                visit[y] = true;
                q.push(y);
            }
        }
    }
}

int main(){
    
    int n, m;
    cin >> n >> m ;
    
    int u, v;
    
    for(int i=0; i<m; i++){
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int cnt = 0;
    
    for(int i=1; i<u; i++){
        if(!visit[i]){
            cnt ++;
            bfs(u);
        }
    }
    
    cout << cnt;
    
    return 0;
}
