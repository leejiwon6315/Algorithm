#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cnt = 0;
    int n;
    vector<int> cars;
    
    cin >> n;
    
    for(int i=0; i<5; i++){
        int input;
        cin >> input;
        cars.push_back(input);
    }
    
    for(int i=0; i<5; i++)
        if(cars[i]%10 == n) cnt ++;
    
    cout << cnt;
    
    return 0;
}
