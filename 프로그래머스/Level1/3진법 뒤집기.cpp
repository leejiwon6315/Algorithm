#include <stack>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> tmp;
    
    while(n/3 != 0){
        tmp.push(n%3);
        n/=3;
    }
    tmp.push(n);
    
    int i=0;
    while(!tmp.empty()){
        answer += tmp.top()*pow(3,i);
        tmp.pop();
        i++;
    }
        
    return answer;
}
