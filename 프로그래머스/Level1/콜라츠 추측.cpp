#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int n = 0;
    int cnt = 0;
    long long a = num;
    while(n < 500){
        
        if(a %2 ==0){
            a = (a/2);
            cnt ++;
            n++;
            if(a==1) break;
            else continue;
        }
        
        else if(a==1)break;
        
        else{
            a = (a*3)+1;
            cnt ++;
            n++;
            if(a==1) break;
            else continue;
        }
    }
    
    if(a == 1){
        answer = cnt;
    }
    else answer = -1;
    
    return answer;
}
