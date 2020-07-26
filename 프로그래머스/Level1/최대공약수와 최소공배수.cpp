#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int cnt = 0;
    int small, k1, k2;
    int big = 0;
    
    if(m>n){
        k1 = n;
        k2 = m; 
    }
    else if(n>m){
        k1 = m;
        k2 = n;
    }
    else{ 
        answer.push_back(m); 
        answer.push_back(n);
    }

    for(int i=1; i<=k2; i++){
        if(k1%i == 0 && k2%i == 0)
        small = i;
        big = (k1*k2)/small;
    }
    answer.push_back(small);
    answer.push_back(big);
    
    
        
    return answer;
}
