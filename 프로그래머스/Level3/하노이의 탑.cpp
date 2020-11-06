#include <string>
#include <vector>
using namespace std;

vector<vector<int>> tmpAnswer;

void hanoi(int n, int from, int tmp, int to){
    if(!n) return;
    
    hanoi(n-1, from, to, tmp);
    tmpAnswer.push_back({from, to});
    hanoi(n-1, tmp, from, to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    if(n==1){
        answer.push_back({1,3});
        return answer;
    }
    
    hanoi(n, 1, 2, 3);
    answer = tmpAnswer;
    return answer;
}
