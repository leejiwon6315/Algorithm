#include <iostream>

using namespace std;

int main(){
    int snack, amount, money;
    cin >> snack >> amount >> money;
    if(money < snack*amount)
        cout << (snack*amount) - money;
    else
        cout << 0;
    
    return 0;
}
