#include <string>
#include <vector>

using namespace std;

int c = 0;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int mincnt = arr[0];
    
    for(int i=0; i<arr.size();i++){
        if(mincnt > arr[i]){
            mincnt = arr[i];
            c = i;
        }
    }
    
    arr.erase(arr.begin()+c);
    
    for(int i=0; i<arr.size();i++) answer.push_back(arr[i]);

    if(arr.size()==0) answer.push_back(-1);
    
    return answer;
}
