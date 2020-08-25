#include <string>
#include <vector>

using namespace std;

bool visit[200];

void dfs(vector<vector<int>> &computers, int n, int start){
    visit[start] = true;
    
    for(int i=0; i<n; i++){
        if(!visit[i] && computers[start][i] == 1){
            dfs(computers, n, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(!visit[i]){
            dfs(computers, n, i);
            answer ++;
        }
    }
    
    return answer;
}
