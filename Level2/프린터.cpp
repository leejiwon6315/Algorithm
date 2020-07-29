#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> sub_q;
    
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i,priorities[i]));
        sub_q.push(priorities[i]);
    }
    
    while(!q.empty()){
        int fisrtQ = q.front().first;
        int secondQ = q.front().second;
        q.pop();
        
        if(secondQ == sub_q.top()){
            sub_q.pop();
            answer ++;
            
            if(fisrtQ == location){
                break;
            }
        }
        else q.push(make_pair(fisrtQ, secondQ));
    }

    return answer;
}
