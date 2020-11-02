#include <iostream>
#include <vector>
#include <cmath>

#define maxi 1000000

using namespace std;

int check[maxi] = {0, };

int mul(int a, int p){
    int tmp = 0;
    while(a){
        tmp += (int)floor(pow(a%10, p));
        a/=10;
    }
    return tmp;
}

void dfs(int a, int p){
    check[a] ++;
    if(check[a] > 2) return;
    dfs(mul(a,p),p);
}

int main(){
    int a, p, cnt=0;
    cin >> a >> p;
    
    dfs(a, p);
    
    for(int i=0; i<maxi; i++){
        if(check[i] == true) cnt ++;
    }
    
    cout << cnt;
    
    return 0;
}
