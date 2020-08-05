#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int cnt = brown + yellow;
    
    for(int i=cnt; i>0; i--){

        if(cnt%i == 0){
            if(( i*2 ) + ( ((cnt/i)-2)*2 ) == brown ){
                answer.push_back(i);
                answer.push_back(cnt/i);
                break;
            }
        }
    }
    
    return answer;
}
