#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool s(int a, int b){
    return a < b;
}

int cnt = 0;
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]%divisor == 0){
            answer.push_back(arr[i]);
            sort(answer.begin(), answer.end(), s);
            cnt ++;
        }
    }
    
    if(cnt == 0) answer.push_back(-1);
    
    return answer;
}
