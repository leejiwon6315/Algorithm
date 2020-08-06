#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> g;
    
    if(s[0] ==')') return false;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            g.push(0);
        }
        else{
            if(!g.empty()){
                g.pop();
            }
        }
    }
    
    if(!g.empty()){
        answer = false;
    }

    return answer;
}
