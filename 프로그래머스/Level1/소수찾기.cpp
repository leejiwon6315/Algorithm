#include <string>
#include <vector>

using namespace std;
int arr[1000000];

int solution(int n) {
    int answer = 0;
    
    for(int i=2; i<=n; i++){
        arr[i]=i;
    }
    for(int i=2; i<=n; i++){
        if(arr[i]==0) continue;
        for(int j=i+i; j<=n; j+=i){
            arr[j]=0;
        }
    }
    for(int i=2; i<=n; i++){
        if(arr[i]!=0){
            answer ++;
        }
    }
    return answer;
}
