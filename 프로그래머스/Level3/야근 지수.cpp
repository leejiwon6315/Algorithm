#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long zero = 0;
    long long size = works.size();
    
    priority_queue<int> q;
    for(int i : works) q.push(i);
    
    while(n){
        if(q.top()==0) break;
        long long input = q.top();
        q.pop();
        q.push(input-1);
        n--;
    }
    
    while(!q.empty()){
        if(q.top()==0){
            q.pop();
            continue;
        }
        answer += pow(q.top(),2);
        q.pop();
    }
    
    return answer;
}
