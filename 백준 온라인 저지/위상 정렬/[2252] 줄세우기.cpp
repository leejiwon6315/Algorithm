#include<iostream>
#include<vector>
#include<queue>
#define max 32001

using namespace std;

int n, m, id[max];
vector<int> a[max];

void tps(){
    int result[max];
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(id[i]==0) q.push(i);
    }
    for(int i=1; i<=n; i++){
        if(q.empty()){
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        
        for(int i=0;i<a[x].size();i++){
            int y=a[x][i];
            
            if(--id[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=1; i<=n;i++){
        cout << result[i] << ' ';
    }
}

int main(void){
    int k1, k2;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        cin >> k1 >> k2;
        a[k1].push_back(k2);
        id[k2]++;
    }
    
    tps();
}
