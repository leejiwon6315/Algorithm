#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> dp(n);
    
    dp[0]=1;
    dp[1]=2;
    
    for(int i=2; i<n; i++){
        dp[i] = dp[i-1]%1234567 + dp[i-2]%1234567;
    }
    
    return dp[n-1]%1234567;
}
