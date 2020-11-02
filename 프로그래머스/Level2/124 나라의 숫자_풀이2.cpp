#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string tmp = "";
    
    while(n){
        if(n%3 == 1) tmp += '1';
        else if(n%3 == 2) tmp += '2';
        else if(n%3 == 0){
            tmp += '4';
            n--;
        }
        n/=3;
    }
    
    for(int i=tmp.length()-1; i>=0; i--)
        answer += tmp[i];
    
    return answer;
}
