#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++){
        if(s[i] != ' '){
            char st = ('A'<= s[i] && s[i] <='Z') ? 'A' : 'a';
            answer += st + (s[i] + n - st)%26;
        }
        else if(s[i] == ' '){
            answer += ' ';
        }
    }
    return answer;
}
