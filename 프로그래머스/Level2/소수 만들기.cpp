#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int answer = 0;

vector<int> numList;
int num[3];

bool primeNum(){
    
    int sum = num[0]+num[1]+num[2];
    
    for(int i=2; i<=sqrt(sum); i++){
        if(sum%i == 0) return false;
    }
    
    return true;
}

void dfs(int inx, int cnt){

    if(cnt == 3){
        if(primeNum()) answer ++;
        
        return;
    }
    
    for(int i=inx; i<numList.size(); i++){
        num[cnt] = numList[i];
        dfs(i+1, cnt+1);
    }
}

int solution(vector<int> nums) {
    numList = nums;
    dfs(0, 0);
    return answer;
}
