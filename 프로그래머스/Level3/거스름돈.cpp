#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {   
    vector<int> num(n + 1);
    
    num[0] = 1;
    
    for(int i : money){
        for(int j=i; j<=n; j++ ){
            num[j] += num[j-i];
            num[j] %= 1000000007;
        }
    }
    return num[n];
}
