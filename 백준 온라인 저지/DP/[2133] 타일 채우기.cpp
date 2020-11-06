#include<iostream>
#define max 30
using namespace std;

int d[max];

int dp(int x){
    if(x==0) return 1;
    if(x==1) return 0;
    if(x==2) return 3;
    
    if(d[x]!=0) return d[x];
    int r=3*dp(x-2);
    for(int i=3;i<=x;i++){
        if(i%2==0){
            r+=2*dp(x-i);
        }
    }
    return d[x]=r;
}

int main(void){
    int n;
    cin >> n ;
    if(n<1)return 0;
    
    cout << dp(n);
    
}
