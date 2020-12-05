#include <iostream>
#include <vector>

using namespace std;

int main (){
    int n, r, c;
    int d[1001];
    vector<vector<long long>> matrix(501, vector<long long>(501, 0));
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> r >> c;
        d[i] = r;
        d[i+1] = c;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {

            int j = len + i - 1;
            matrix[i][j] = 2147483648;
            
            for(int k=i; k<j; k++){
                matrix[i][j] = min(matrix[i][k] + matrix[k+1][j] + d[i-1]*d[k]*d[j], matrix[i][j]);
            }
        }
    }
    
    cout << matrix[1][n];
    
    return 0;
}
