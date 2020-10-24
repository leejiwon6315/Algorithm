#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<int> a[501];
int result[501], id[501], Time[501];

void tps(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(id[i]==0){
            result[i]=Time[i];
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        for(int j=0; j<a[x].size(); j++){
            int y=a[x][j];
            result[y] = max(result[y], result[x]+Time[y]);
            if(--id[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=1; i<=n;i++){
        cout << result[i] << '\n';
    }
}
int main(void){
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> Time[i];
        while(1){
            int x;
            cin >> x;
            if(x == -1) break;
            id[i]++;
            a[x].push_back(i);
        }
    }
    tps();
}

