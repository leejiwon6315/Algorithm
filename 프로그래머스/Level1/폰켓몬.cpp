#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pick = 0;
    
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == nums[i+1]){
            continue;
        }
        pick ++;
    }
    
    if(pick == nums.size()/2 || pick < nums.size()/2) answer = pick;
    else{
        answer = nums.size()/2;
    }
    
    return answer;
}
