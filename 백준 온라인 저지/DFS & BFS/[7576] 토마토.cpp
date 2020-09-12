#include <iostream>
#include <vector>
#include <queue>
#define max 1001

using namespace std;

int box[max][max];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int m, n;
int x, y;

queue<pair<int, int>> q;

void bfs(){
    
    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(box[ny][nx] == 0){
                    box[ny][nx] = box[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main(){
    int cnt = 0;
    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> box[i][j] ;
            
            if(box[i][j]==1){
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j]==0){
                cout << -1;
                return 0;
            }
            
            if(box[i][j] > cnt) cnt = box[i][j];
        }
    }
    
    cout << cnt-1;
    
    return 0;
}


