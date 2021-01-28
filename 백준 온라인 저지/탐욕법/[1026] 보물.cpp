#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void loopFunc(vector<int> &Arr, int n){
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        Arr.push_back(input);
    }
}

int main(){
    int n, answer=0;
    vector<int> A, B;
    
    cin >> n;
    
    loopFunc(A, n);
    loopFunc(B, n);
    
    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i<n; i++)
        answer += A[i]*B[i];
    
    cout << answer;
    
    return 0;
}
