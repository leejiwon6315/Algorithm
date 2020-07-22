#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0; 
    int cnt = 0;
    int num = 0; 
    
        while(1){
            cnt += n%10;
            if(n/10 == 0) break;
            n = n/10;
        }
    
    answer = cnt;
    return answer;
}
