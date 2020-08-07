#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int map[8][8];
int copymap[8][8];

int resultCnt = 0;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void copyMap(int (*copy)[8], int (*body)[8]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            copy[i][j] = body[i][j];
        }
    }
}

int checkClean(int (*spread)[8]){
    int cleanCnt = 0;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!spread[i][j])
                cleanCnt ++;
    
    return cleanCnt;
}

void bfs(){
    
    int spread[8][8];
    queue<pair<int, int>> q;
    
    copyMap(spread, copymap);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(spread[i][j] == 2)
                q.push(make_pair(i, j));
   
    
    while(!q.empty()){
        
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i=0; i<4; i++){
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(!spread[ny][nx]){
                    spread[ny][nx] = 2;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    
    int cleanArea = checkClean(spread);
    resultCnt = max(resultCnt, cleanArea);
}

void wall(int wallCnt){
    if(wallCnt == 3){
        bfs();
        return;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!copymap[i][j]){
                copymap[i][j] = 1;
                wall(wallCnt+1);
                copymap[i][j] = 0;
            }
        
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> map[i][j];
    
    for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!map[i][j]){
                    copyMap(copymap, map);
                    copymap[i][j] = 1;
                    wall(1);
                    copymap[i][j] = 0;
                }
    
    cout << resultCnt;
    
    return 0;
}
