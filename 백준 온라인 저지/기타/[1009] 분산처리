#include <iostream>

using namespace std;

int main(void){
    int t, a, b;
    
    cin >> t;
    
    while(t--){
        cin >> a >> b;
        
        int tmp = a;
        
        if(b==1){
            a = a%10;
            if(a==0) a = 10;
            
            cout << a << endl;
            continue;
        }
        else{
            for(int j=0;j<b-1;j++) a = (a*tmp)%10;
            if(a==0) a = 10;
        }
 
        cout << a << "\n";
    }
    return 0;
}
