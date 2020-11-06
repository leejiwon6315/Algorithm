#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int c[1001][1001];
int map[1001][1001];

void dp(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j]+map[i][j];
            }
            else c[i][j]=c[i][j-1]+map[i][j];
        }
    }
}

int main(void){
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j] ;
        }
    }

    dp(n,m);
    int ans=c[n][m];
    cout << ans ;
}

