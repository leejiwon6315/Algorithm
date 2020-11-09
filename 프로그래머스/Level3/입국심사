#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long avePeople = 0;
    
    sort(times.begin(), times.end());
    
    long long takeTime = times.size();
    long long minTime = 1;
    long long maxTime = times[takeTime-1] * (long long)n;
    
    while(minTime <= maxTime){
        long long mid = ((minTime + maxTime)/2);
        
        for(int i=0; i<takeTime; i++) avePeople += (mid/times[i]);
        
        if(n <= avePeople){
            answer = mid;
            maxTime = mid - 1;
        }
        else minTime = mid + 1;

        avePeople = 0;
    }
    
    return answer;
}
