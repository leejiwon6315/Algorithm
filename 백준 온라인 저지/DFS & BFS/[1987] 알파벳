#include <iostream>
#include <algorithm>
#define Maxi 20

using namespace std;

char arr[Maxi][Maxi] = {};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r, c;
bool check[26];

int dfs(int a, int b, int alp){
    
    check[alp-'A'] = true;

    int cnt = 0;
    
    for(int i=0; i<4; i++){
        int nx = b+dx[i];
        int ny = a+dy[i];
        
        if(nx>=0 && ny>=0 && nx<c && ny<r){
            int next = arr[ny][nx];
            
            if(!check[next-'A']){
                check[next-'A'] = true;
                cnt = max(cnt, dfs(ny, nx, next));
                check[next-'A'] = false;
            }
        }
    }
    return cnt+1;
}

int main(){
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << dfs(0,0,arr[0][0]);
    
    return 0;
}
