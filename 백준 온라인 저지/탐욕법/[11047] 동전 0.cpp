#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n = 0, k = 0, answer = 0;
    
    vector<int> v;
    
    cin >> n >> k;
    
    while(n--){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<v.size(); i++){
        if(k<v[i]) continue;
        while(v[i]<=k){
            k -= v[i];
            answer ++;
        }
    }
    
    cout << answer;
    return 0;
}
