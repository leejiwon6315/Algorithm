#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s){
    int answer = 0;
    stack<char> stk;
   
    for(int i=0; i<s.length(); i++){
        if(stk.size() > 0 && stk.top() == s[i]){
            stk.pop();
        }
        else{
            stk.push(s[i]);
        }
    }
    
    if(stk.empty()) return 1;
    return answer;
}
