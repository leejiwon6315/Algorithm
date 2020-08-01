#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int firstT = 0, secondT = 0;
    while(pq.size()>1 && pq.top() < K){        
        
        if(pq.top() < K){
            firstT = pq.top();
            pq.pop();
            secondT = pq.top();
            pq.pop();
            
            firstT += secondT*2;
            pq.push(firstT);
            
            answer ++;     

        }
    }
    
    if(pq.top() < K) return -1;

    return answer;
}
