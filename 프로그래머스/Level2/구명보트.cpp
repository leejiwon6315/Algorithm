#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    int small = 0, big = people.size() - 1;
        
    sort(people.begin(), people.end(),less<int>());
    
    while(small <= big){
        if(people[small] + people[big] > limit){
            big --;
            answer ++;
        }
        else{
            small ++;
            big --;
            answer ++;
        }
    }
    
    return answer;
}
