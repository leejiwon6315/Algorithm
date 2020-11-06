#include <string>
#include <vector>

using namespace std;

int zero = 0, one = 0;
void dq(int x, int y, int size, vector<vector<int>> tmp){
    bool checkOne = true, checkZero = true;
    for(int i=x; i< x+size; i++){
        for(int j=y; j< y+size; j++){
            if(tmp[i][j]==0) checkOne = false;
            if(tmp[i][j]==1) checkZero = false;
        }
    }
    if(checkOne){
        one ++;
        return;
    }
    if(checkZero){
        zero ++;
        return;
    }

    dq(x, y, size/2, tmp);
    dq(x + size/2, y, size/2, tmp);
    dq(x, y + size/2, size/2, tmp);
    dq(x + size/2, y + size/2, size/2, tmp);
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    dq(0,0,arr.size(),arr);
    
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
