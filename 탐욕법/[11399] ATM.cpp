#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n = 0, answer = 0;
    vector<int> p;
    
    cin >> n;
    
    while(n--){
        int tmp; 
        cin >> tmp;
        p.push_back(tmp);
    }
   
    sort(p.begin(), p.end(), less<int>());
    
    int stack = 0;
    for(int i: p){
        stack += i;
        answer += stack;
    }
    
    cout << answer;
    return 0;
}
