#include <string>
#include <vector>

using namespace std;

vector <int> arr;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int minus = lost.size();
    
    for(int i=0; i<n; i++){
        arr.push_back(i);
    }
    
    for(int i=0; i<lost.size(); i++){
        answer --;
        
        for(int j=0; j<reserve.size(); j++){ 
            if(lost[i]==reserve[j]){
                
                lost.erase(lost.begin()+i);
                reserve.erase(reserve.begin()+j);
                i--;
                j--;
                answer ++;
            }
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]+1==reserve[j]){
                
                reserve.erase(reserve.begin()+j);
                answer++;
                break;
            }
            else if(lost[i]-1==reserve[j]){

                reserve.erase(reserve.begin()+j);
                answer++;
                break;
            }
            else continue;
        }
    }


    return answer;
}
