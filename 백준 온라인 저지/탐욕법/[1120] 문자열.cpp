#include <iostream>
#include <string>

using namespace std;

int main(void){
    string a, b;
    int min = 50;
    
    cin >> a >> b;
    
    for(int len=0; len<=b.length()-a.length(); len++){
        int cnt = 0;
        
        for(int j=0; j<a.length(); j++){
            if(a[j] != b[j+len]) cnt++;
        }
        
        if(min > cnt) min = cnt;

    }
    
    cout << min;
    
    return 0;
}
