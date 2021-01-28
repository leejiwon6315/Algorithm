#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100001

using namespace std;
int n;
int A[MAX];

void findNum(int k){
    int start = 0, end = n-1;
    
    while(end >= start){
        int mid = (end+start)/2;
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
    int input, m;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    sort(A, A+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &input);
        findNum(input);
    }

    return 0;
}
