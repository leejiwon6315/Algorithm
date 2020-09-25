#include <string>
#include <vector>

using namespace std;
int answer = 9;

void dfs(int N, int number, int currentNum, int cnt){
    if(cnt > 8) return;
    
    if(number == currentNum){
        answer = min(cnt, answer);
        return;
    }
    
    int tmp = 0;
    for(int i=0; i<9; i++){
        tmp = (tmp*10) + N;
        dfs(N, number, currentNum + tmp, cnt+i+1);
        dfs(N, number, currentNum - tmp, cnt+i+1);
        
        if(currentNum != 0){
            dfs(N, number, currentNum * tmp, cnt+i+1);
            dfs(N, number, currentNum / tmp, cnt+i+1);
        }
    }
    
}

int solution(int N, int number) {
    
    dfs(N, number, 0, 0);
    if(answer == 9) return -1;

    return answer;
}
