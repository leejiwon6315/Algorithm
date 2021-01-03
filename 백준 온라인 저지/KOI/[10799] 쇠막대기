#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin >> input;
    
    int cnt = 0, total = 0;
    for(int i=0; i<input.length(); i++){
        
        if(input[i] == '(') cnt ++;
        else{
            cnt --;
            
            if(input[i-1] == ')') total += 1;
            else total += cnt;
        }
    }
    
    cout << total;
    return 0;
}
