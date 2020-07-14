#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    //unique : vector의 중복원소를 제거하는 함수
    
    vector<int> answer = arr;
    return answer;
}
