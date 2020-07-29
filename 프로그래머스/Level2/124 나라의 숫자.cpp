#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int s = 0;
    
    while(n > 0){
        s = n%3;
        if(s == 0){
            s = 4;
            n = (n/3) - 1;
        }
        else n /= 3;
        answer.insert(0, to_string(s));
    }

    return answer;
}
