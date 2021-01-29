#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 500001

using namespace std;
long long n;
long long A[MAX];

void findNum(long long k){
    long long start = 0, end = n-1;
    
    while(end >= start){
        long long mid = (end+start)/2;
        if(k == A[mid] || k == A[start] || k == A[end]){
            printf("1\n");
            return;
        }
        else if(k<A[mid]){
            end = mid-1;
        }
        else if(k>A[mid]){
            start = mid+1;
        }
    }
    
    printf("0\n");
    return;
}

int main(){
    long long input, m;
    
    scanf("%lld", &n);
    for(long long i=0; i<n; i++){
        scanf("%lld", &A[i]);
    }
    sort(A, A+n);
    
    scanf("%lld", &m);
    for(long long i=0; i<m; i++){
        scanf("%lld", &input);
        findNum(input);
    }

    return 0;
}
