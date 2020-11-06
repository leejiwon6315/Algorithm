#include <string>
#include <vector>

using namespace std;

vector<vector<int>> tmp;

void dfs(int x, int y, int size, vector<int> &answer){
    bool checkOne = true, checkZero = true;
    
    for(int i=x; i< x+size; i++){
        for(int j=y; j< y+size; j++){
            if(tmp[i][j]==0) checkOne = false;
            if(tmp[i][j]==1) checkZero = false;
        }
    }
    if(checkOne){
        answer[1] ++;
        return;
    }
    if(checkZero){
        answer[0] ++;
        return;
    }

    dfs(x, y, size/2, answer);
    dfs(x + size/2, y, size/2, answer);
    dfs(x, y + size/2, size/2, answer);
    dfs(x + size/2, y + size/2, size/2, answer);
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    
    tmp = arr;
    dfs(0,0,arr.size(),answer);
    
    return answer;
}
