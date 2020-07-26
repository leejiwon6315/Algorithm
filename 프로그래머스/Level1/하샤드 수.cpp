#include <string>
#include <vector>

using namespace std;

vector<int> nj;

bool solution(int x) {
    bool answer = true;
    int n = x;
    
    while(1){

        nj.push_back(n%10); 
        if(n/10 == 0) break;
        n = n/10;
        
    }
    
    int sum = 0;
    for(int i=0; i<nj.size(); i++){
        sum += nj[i];
    }
    
    if(x%sum == 0) answer=true;
    else answer=false;
    
    return answer;
}
