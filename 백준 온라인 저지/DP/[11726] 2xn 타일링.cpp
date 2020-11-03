#include<iostream>
#define max 1000
using namespace std;

int d[max];

int dp(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(d[x]!=0) return d[x];
    return d[x]=(dp(x-1)+dp(x-2))%10007;
}

int main(void){
    int n;
    cin >> n ;
    if(n<1)return 0;
    
    cout << dp(n);
    
}
