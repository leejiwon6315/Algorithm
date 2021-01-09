#include <iostream>
#include <queue>
#define MAX 1501
using namespace std;

int r, c, firstBirdX = -1, firstBirdY, secondBirdX, secondBirdY, cnt = 0, okay = 0;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int visit[MAX][MAX] = {0, };
int visitDot[MAX][MAX] = {0, };
char map[MAX][MAX];
queue<pair<int, int>> q, dot;

void bfs(int y, int x){

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if(x == secondBirdX && y == secondBirdY){
            okay = 0;
            cout << cnt << "\n";
            return;
        }
        okay = 1;

        for(int i=0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && ny >= 0 && nx < c && ny < r){
                if(!visit[ny][nx] && map[ny][nx] != 'X') q.push({ny, nx});
                visit[ny][nx] = 1;
            }
        }
    }
}

void bfsDot(){

    unsigned long dotSize = dot.size();
    while(dotSize--){
        int x = dot.front().second;
        int y = dot.front().first;
        dot.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < c && ny < r){
                if(!visitDot[ny][nx] && map[ny][nx] == 'X'){
                    visitDot[ny][nx] = 1;
                    map[ny][nx] = '.';
                    dot.push({ny, nx});

                    if(visit[ny][nx]) q.push({ny, nx});
                }
            }
        }
    }
}

int main(){

    cin >> r >> c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];

            if(map[i][j] == 'L'){
                if(firstBirdX == -1){
                    firstBirdX = j;
                    firstBirdY = i;
                }
                else{
                    secondBirdX = j;
                    secondBirdY = i;
                }
            }

            if(map[i][j] != 'X'){
                dot.push({i, j});
                visitDot[i][j] = 1;
            }
        }
    }

    q.push({firstBirdY, firstBirdX});
    visit[firstBirdY][firstBirdX] = 1;

    while(unsigned long qSize = q.size()){
        bfs(firstBirdY, firstBirdX);

        if(!okay) return 0;

        bfsDot();
        cnt ++;
    }

    return 0;
}

