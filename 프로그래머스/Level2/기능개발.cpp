#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int mok=0, na=0, max=0;
    
    
    for(int i=0; i<progresses.size(); i++){
        mok = (100 - progresses[i])/speeds[i];
        na = (100 - progresses[i])%speeds[i];
        if(na != 0) mok ++;
        
        if(max<mok){
            answer.push_back(1);
            max = mok;
        }
        else{
            int tmp = answer.back();
            answer.pop_back();
            answer.push_back(++tmp);
        }
    }
    

    return answer;
}
