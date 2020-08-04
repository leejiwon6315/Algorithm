#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max 26

using namespace std;

int map[max][max] = {0, };
bool visit[max][max];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(int y, int x, int n){
    int cnt = 0;
    
    if(map[y][x] == 1){
        
        queue<pair<int, int>> q;
        q.push(make_pair(y, x));
        visit[y][x] = true;
        
        while(!q.empty()){
            y = q.front().first;
            x = q.front().second;
            q.pop();
            
            cnt ++;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && ny>=0 && ny<n && nx<n){
                    if(map[ny][nx] == 1 && !visit[ny][nx]){
                        q.push(make_pair(ny, nx));
                        visit[ny][nx] = true;
                    }
                }
            }
        
        }
    }
    
    return cnt;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int> result;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) scanf("%1d", &map[i][j]);

    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(!visit[i][j] && map[i][j] == 1){
                int answer = bfs(i, j, n);
                result.push_back(answer);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for(int i : result) cout << i << "\n";
    
    return 0;
}
