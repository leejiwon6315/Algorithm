#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    int temp = 0;
    
    for(int i=0; i<arr.size(); i++){
        temp = temp + arr[i];
        
    }
    answer = (double)temp/arr.size();
    
    
    return answer;
}
