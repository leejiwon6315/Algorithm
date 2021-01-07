#include <iostream>
#include <algorithm>
#define MAX 110

using namespace std;

int amount, knapsack;
int dp[MAX][100010];
int weight[MAX];
int price[MAX];

int main(){

    cin >> amount >> knapsack;

    for(int i=1; i<=amount; i++)
        cin >> weight[i] >> price[i];

    for(int i=1; i<=amount; i++){
        for(int j=1; j<=knapsack; j++){

            if(j >= weight[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + price[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
                
            }
        }
    }

    cout << dp[amount][knapsack] << "\n";

    return 0;
}
