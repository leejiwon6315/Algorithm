#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[101][101] = {0, };
int n;
bool check[101];


void setting(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void dfs(int x){
    
    for(int i=0; i<n; i++){
        if(!check[i] && map[x][i]){
            check[i] = true;
            dfs(i);
        }
    }
}

int main(){
    
    setting();
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    
    for(int i=0; i<n; i++){
        memset(check, false, sizeof(check));
        dfs(i);
        
        for(int j=0; j<n; j++){
            if(check[j]) map[i][j] = 1;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
