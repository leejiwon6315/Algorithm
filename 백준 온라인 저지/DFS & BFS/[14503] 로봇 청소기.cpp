#include<iostream>
#include<cstring>
#include<algorithm>

#define max 51

using namespace std;

int map[max][max];

int zx, zy, zd;
int num=0;

int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int nx, ny, d;
int h, w;

int dir(int now){
    if(now==0){
        return 0;
    }
    else if(now==1){
        return 3;
    }
    else if(now==2){
        return 2;
    }
    else{
        return 1;
    }
}

void dfs(int y, int x, int d){
    if(!map[y][x]){
        num++;
        map[y][x]=2;
    }
    for(int i=d+1;i<d+5;i++){
            nx=x+dx[i%4];
            ny=y+dy[i%4];
        
        if(nx>=0 && ny>=0 && nx<w && ny<h){
            if(!map[ny][nx]){
                dfs(ny,nx,i%4);
            }
        }
    }
    int xx=x+dx[(d+2)%4];
    int yy=y+dy[(d+2)%4];
    
    if(map[yy][xx]==2){
        dfs(yy,xx,d%4);
    }
    else if(map[yy][xx]==1){
        cout << num << endl;
        exit(0);
    }
    
}

int main(){
    cin >> h >> w;
    
    cin >> zy >> zx >> zd;
    
    memset(map, 0, sizeof(map));
    num=0;
    
    int dd=dir(zd);
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
        }
    }
    
    dfs(zy,zx,dd);
    
    cout << num << endl;
    
    return 0;
}
