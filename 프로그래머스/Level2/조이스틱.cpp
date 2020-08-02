#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int num = name.length(), tmp = 0, fast = num-1;
    
    for(int i=0; i<num; i++){
        tmp += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int nextCharIdx = i+1;
        while(nextCharIdx < num && name[nextCharIdx] == 'A') nextCharIdx++;
        
        fast = min(fast, i + num - nextCharIdx + min(i, num - nextCharIdx));
        
    }
    tmp += fast;
    answer = tmp;
    return answer;
}
