#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[1001];
bool visit[1001];

void dfs(int x){
    visit[x]=true;
    
    for(int i=1; i<arr[x];i++){
        int y=arr[x];
        if(!visit[y]){
            dfs(y);
        }
    }
   
}

int main(void){
    int q1, q2;
    int num=0;
    
    cin >> q1;
    for(int i=0;i<q1;i++){
        
        cin >> q2;
        
        for(int j=1;j<=q2;j++){
            cin >> arr[j];
        }
        for(int j=1; j<=q2;j++){
            if(!visit[j]){
                dfs(j);
                num++;
            }
        }
        cout << num << '\n';
        
        memset(visit, false, sizeof(visit));
        num =0;
        }
        return 0;
    }
