#include <iostream>
#define max 51
int m, n;

using namespace std;

int map[max][max];
bool check[max][max];

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void dfs(int y, int x){
    check[y][x] = true;
    
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(nx>=0 && ny>=0 && ny<n && nx<m){
            if(!check[ny][nx] && map[ny][nx]){
                check[ny][nx] = true;
                dfs(ny, nx);
            }
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tCase;
    cin >> tCase;
    
    for(int cycle = 0; cycle<tCase; cycle++){
        
        cin >> m >> n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                map[i][j] = 0;
                check[i][j] = false;
            }
        }
        
        int k;
        cin >> k;
        
        int x, y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            map[y][x] = 1;
        }
        
        int cnt=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!check[i][j] && map[i][j]){
                    dfs(i,j);
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}
