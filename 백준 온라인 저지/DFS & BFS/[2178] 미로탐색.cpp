#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int n, m;
int map[101][101] = {0,};
int check[101][101] = {0,};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void Bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(check[nx][ny]==0 && map[nx][ny]==1){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = check[x][y] + 1;
                }
            }
        }
    }
}

int main(){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
            // 문제에서 주어지는 입력값 문자열에 띄어쓰기가 없기 때문에 scanf를 사용하여 %1d 로 한글자씩 입력받음
        }
    }
    
    Bfs(0, 0);
    
    cout << check[n-1][m-1] << endl;
    return 0;
}
