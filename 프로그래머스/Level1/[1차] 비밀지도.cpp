#include <string>
#include <vector>

using namespace std;
vector<string> sharp;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        answer.push_back("");
        
        for(int j=0; j<n; j++){
            
            if(arr1[i]%2 || arr2[i]%2) sharp.push_back("#");
            else sharp.push_back(" ");
            
            arr1[i]=arr1[i]/2;
            arr2[i]=arr2[i]/2;
        }
        
        for(int k=n-1; k>=0; k--){
            answer[i] += sharp[k];
        }
        sharp.clear();
    }
    

    return answer;
}
