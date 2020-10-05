#include <iostream>

using namespace std;

int main(void){
    int coin = 0, price = 0;
    cin >> price ;
    
    price = 1000 - price;
    
    while(price >= 500){
        price -= 500;
        coin ++;
    }
    while(price >= 100){
        price -= 100;
        coin ++;
    }
    
    while(price >= 50){
        price -= 50;
        coin ++;
    }
    
    while(price >= 10){
        price -= 10;
        coin ++;
    }
    
    while(price >= 5){
        price -= 5;
        coin ++;
    }
    
    while(price >= 1){
        price --;
        coin ++;
    }
    
    cout << coin;
    
    return 0;
}
