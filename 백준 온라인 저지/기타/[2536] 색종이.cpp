#include <iostream>

using namespace std;

int main(){
    int map[100][100]={0, };

    int n;
    cin >> n;
        
    int a, b, cnt=0;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        
        int x = a+10;
        int y = b+10;
            
        for(int j=a; j<x; j++){
            for(int k=b; k<y; k++){
                map[j][k] = 1;
            }
        }
    }
        
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j] == 1) cnt++;
        }
    }
        
    cout << cnt << endl;
        
    return 0;
}
