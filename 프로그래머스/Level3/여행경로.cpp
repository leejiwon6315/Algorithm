#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool dfs(string start,vector<vector<string>> &tickets, vector<string> &answer, vector<string> &tmp, vector<bool> &v, int path){
    
    tmp.push_back(start);
    
    if(path == tickets.size()){
        answer = tmp;
        return true;
    }
    
    for(int i=0; i<tickets.size(); i++){
        if(start == tickets[i][0] && !v[i]){
            v[i] = true;
            
            bool rightPath = dfs(tickets[i][1],tickets,answer,tmp, v, path+1);
            if(rightPath) return true;
            v[i] = false;
        }
    }
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> v(tickets.size(), false);
    vector<string> answer, tmp;
    
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs("ICN",tickets, answer, tmp, v, 0);
   
    return answer;
}
