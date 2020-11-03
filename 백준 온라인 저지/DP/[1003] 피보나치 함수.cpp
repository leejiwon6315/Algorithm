#include<iostream>
#include<cstring>
#define max 40

using namespace std;

int d[max];

int dp(int x){
    if(x==0){
        return 0;
        
    }
    else if(x==1){
        return 1;
    }
    else if(x==2) return 1;
    
    if(d[x]!=0) return d[x];
    else{
        d[x]=dp(x-1)+dp(x-2);
        return d[x];
    }
}

int main(void){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n ;
        dp(n);
        
        if(n==0){
            cout << '1' << ' ' << '0' <<endl;
        }
        else if(n==1){
            cout << '0' << ' ' << '1' <<endl;
        }
        
        else{
            cout << dp(n-1) << ' ' << dp(n) <<endl;
        }
        memset(d,0,sizeof(d));
    }
}
