#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> skillTreeOrder;
    
    for(int i=0; i<skill.length(); i++){
        skillTreeOrder[skill[i]] = i+1;
    }
    
    for(string skt:skill_trees){
        int cnt = 1;
        bool check = true;
        
        for(int i=0; i<skt.length(); i++){
            if(skillTreeOrder[skt[i]] > cnt){
                check = false;
                break;
            }
            else if(skillTreeOrder[skt[i]] == cnt){
                cnt ++;
            }
        }
        if(check) answer ++;
    }
        
    return answer;
}
