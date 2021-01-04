#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a, b;
    int aCnt=0, bCnt=0;
    
    for(int i=0; i<10; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }
    for(int i=0; i<10; i++){
        int input;
        cin >> input;
        b.push_back(input);
    }
    
    for(int i=0; i<10; i++){
        if(a[i]>b[i]){
            aCnt ++;
        }
        else if (a[i] == b[i]){}
        else{
            bCnt ++;
        }
    }
    
    if(aCnt > bCnt) cout << "A";
    else if(aCnt == bCnt) cout << "D";
    else cout << "B";
    
    return 0;
}
