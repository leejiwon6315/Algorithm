#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a = {1,2,3,4,5};
vector<int> b = {2,1,2,3,2,4,2,5};
vector<int> c = {3,3,1,1,2,2,4,4,5,5};

vector<int> cnt(3);

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i=0; i<answers.size(); i++){
        if(a[i%5] == answers[i]) cnt[0] ++; 
        if(b[i%8] == answers[i]) cnt[1] ++; 
        if(c[i%10] == answers[i]) cnt[2] ++;
    }
    
    int Maxcnt = max( max(cnt[0], cnt[1]), cnt[2]);

    for(int i=0; i<3; i++){
        if(Maxcnt == cnt[i]) answer.push_back(i+1);
    }
                    
    return answer;
}
