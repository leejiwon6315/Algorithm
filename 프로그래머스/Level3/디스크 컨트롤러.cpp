#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool orderFn(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int nextStart = 0, sumTime = 0; 
    int size = jobs.size();
    
    sort(jobs.begin(), jobs.end(), orderFn);
    
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= nextStart){
                
                nextStart += jobs[i][1];
                sumTime += (nextStart - jobs[i][0]);
                
                jobs.erase(jobs.begin()+i);
                break;
            }
            if(i == jobs.size()-1) nextStart ++;
        }
    }
    
    return sumTime/size;
}
