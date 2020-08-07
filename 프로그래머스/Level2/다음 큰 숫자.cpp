#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0;
    
    int next1 = n;
    
    while(next1 > 0){
        if(next1%2 == 1) cnt ++;
        next1/=2;
    }
       
    while(1){
        n++;
        int next2 = n;
        int cnt2=0;
        while(next2 > 0){    
            if(next2%2 == 1) cnt2 ++;
            next2/=2;
        }
        if(cnt == cnt2){
            answer = n;
            break;
        } 
    }
    
    return answer;
}
