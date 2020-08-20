#include<iostream>
#include<cstring>
#define max 50
using namespace std;
int map[max][max];
bool visit[max][max];
int num=0;
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={1,0,-1,1,-1,1,0,-1};
int x,y;
void dfs(int y, int x){
    visit[y][x]=true;
    for(int i=0; i<8; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<max && ny<max){
            if(map[ny][nx]&& !visit[ny][nx]){
                visit[ny][nx]=true;
                dfs(ny,nx);
            }
        }
    }
}
int main(){
    while(1){
        cin >> x >> y;
        if(!x&&!y) break;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if(map[i][j] && !visit[i][j]){
                    num++;
                    dfs(i,j);
                }
            }
        }
        cout << num << '\n';
        memset(map, false, sizeof(map));
        memset(visit, false, sizeof(visit));
        num=0;
    }
    return 0;
}
