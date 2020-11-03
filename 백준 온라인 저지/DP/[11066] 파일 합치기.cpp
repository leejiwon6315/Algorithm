#include <memory.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define maxi 501

using namespace std;

int k;
int dp[maxi][maxi];
int cost[maxi];
int file[maxi];

int merge(int i, int j){
    if(i==j) return 0;
    int &result = dp[i][j];
    
    if(result == -1){
        for(int p=i; p<j; p++){
            int tmp = merge(i, p) + merge(p+1, j) + cost[j] - cost[i-1];
            if(result == -1 || result > tmp) result = tmp;
        }
    }
    
    return result;
}


int main(){
    int t;
    cin >> t;
    
    while(t--){
        cin >> k;
        memset(dp, -1, sizeof(dp));
        
        for(int i=1; i<=k; i++){
            cin >> file[i];
            cost[i] = file[i] + cost[i-1];
        }
        
        cout << merge(1, k) << "\n";
    }
    return 0;
}
