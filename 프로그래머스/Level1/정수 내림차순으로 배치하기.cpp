#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool ne(int a, int b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    
    while(1){       
        if(n/10 == 0 && n%10 == 0) break;
        arr.push_back(n%10);
        n = n/10;
    }
    
    sort(arr.begin(), arr.end(), ne);
    
    for(int i=0; i<arr.size(); i++){
        answer += arr[i];
        answer *=10;
    }
    return answer/10;
}
