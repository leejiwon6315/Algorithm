#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int dp[11];
    
    while(t--){
        dp[1] = 1, dp[2] = 2, dp[3] = 4;
        int n;
        
        cin >> n;
        for(int i=4; i<=n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        cout << dp[n] <<"\n";
    }
    
    return 0;
}
