#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string number, int k) {
    string answer = "";
    
    int start = 0;
    
    for(int i = 0; i < number.length() - k; i++){
        
        char max = number[start];
        int maxIdx = start;
        
        for(int j = start; j <= k+i; j++){
            
            if(number[j] > max){
                max = number[j];
                maxIdx = j;
            }
        }        
        answer += max;
        start = ++maxIdx;
    }
            
    return answer;
}
