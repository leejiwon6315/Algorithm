#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num;
    
    for(int j=1; j<=n; j++){
        for(int i=j; i<=n; i++){
            num += i;
            if(num == n){
                answer ++;
                break;
            }
            else if(num > n){
                break;
            }
        }
        num = 0;
    }
    
    return answer;
}
