#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

#define max 1001

using namespace std;

bool visit[max];
vector<int> arr[max];

void dfs(int start){
    visit[start] = true;
    cout << start << " ";
    
    for(int i=0; i<arr[start].size(); i++){
        int y = arr[start][i];
        if(!visit[y]) dfs(y);
    }
}

void bfs(int start){
    queue<int> q;
    visit[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        
        for(int i=0; i<arr[front].size(); i++){
            int y = arr[front][i];
            if(!visit[y]){
                visit[y] = true;
                q.push(y);
            }
        }
    }
}

int main(){
    int input1, input2;
    int N, M, V;
    
    cin >> N >> M >> V;
    
    for(int i=0;i<M;i++){
        cin >> input1 >> input2 ;
        arr[input1].push_back(input2);
        arr[input2].push_back(input1);
    }
    for(int i=0;i<=N;i++){
        sort(arr[i].begin(),arr[i].end());
    }
    dfs(V);
    
    memset(visit,false,sizeof(visit));
    // 기존 visit 배열을 사용하기 위해 메몰 초기화
    
    cout << "\n";
    bfs(V);
    
    return 0;
}
