#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    
    sort(arr.begin(), arr.end(), less<int>());
    int i = 1;
    int max = arr[arr.size()-1];
    
    vector<int> num;
    
    while(1){
        int cnt = 0;
        for(int j=0; j<arr.size(); j++){
            if((max*i)%arr[j] == 0){
                cnt ++;
            }
        }
        if(cnt == arr.size()) return max*i;
        i++;
    }
}
