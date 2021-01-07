#include<iostream>
#include<algorithm>
using namespace std;

int d[1001][3];
int cost[1001][3];

int main(void){
    int n;
    cin >> n ;
    
    for(int i=1;i<=n;i++){
            cin >> cost[i][0] >> cost[i][1] >> cost[i][2] ;
    }
    
    for(int i=1;i<=n;i++){
        d[i][0]=min(d[i-1][1],d[i-1][2])+cost[i][0];
        d[i][1]=min(d[i-1][0],d[i-1][2])+cost[i][1];
        d[i][2]=min(d[i-1][0],d[i-1][1])+cost[i][2];
    }
    
    cout <<  min(min(d[n][0],d[n][1]),d[n][2]);
    
}
