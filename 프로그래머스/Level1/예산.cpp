#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int result = 0;
    
    sort(d.begin(),d.end(), less<int>());
    
    for(int num : d){
        result += num;
        if(result > budget) break;
        else answer ++;
    }
    return answer;
}
