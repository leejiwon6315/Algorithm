#include<iostream>
#include<queue>
#include<cstring>

#define max 101
using namespace std;

int dz[6]={0,0,0,0,1,-1};
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,-1,1,0,0,0};
int arr[max][max][max];
int rst=0;
int a, b, c;

struct tomato{
    int z, y, x ;
};

queue<tomato> q;

void bfs(void){
    while(!q.empty()){
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for(int i=0; i<6; i++){
            int nz=z+dz[i];
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(nx>=0&&ny>=0&&nz>=0&&nx<a&&ny<b&&nz<c){
                if(arr[nz][ny][nx]==0){
                    arr[nz][ny][nx]=arr[z][y][x]+1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }
}

int main(){
    cin >> a >> b >> c;
    for(int h=0;h<c;h++){
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++){
                cin >> arr[h][i][j] ;
                if(arr[h][i][j]==1){
                    q.push({h,i,j});
                }
            }
        }
    }
    bfs();
    for(int h=0;h<c;h++){
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++){
                if(arr[h][i][j]==0){
                    cout << "-1" ;
                    return 0;
                }
                if(rst<arr[h][i][j]){
                    rst=arr[h][i][j];
                }
            }
        }
    }
    cout << rst-1 ;
    
    return 0;
}

