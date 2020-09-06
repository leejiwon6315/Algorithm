#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define max 101

using namespace std;
bool visit[max];
vector<int> map[max];
int k1;
int k2;
int num=0;

void dfs(int x){
    visit[x]=true;
    
    for(int i=0;i<map[x].size();i++){
        int y=map[x][i];
        if(!visit[y]){
            num++;
            dfs(y);
        }
    }
}

int main(){
    int a, b;
    
    cin >> a >> b;
    
    for(int i=0; i<b; i++){
        cin >> k1 >> k2 ;
        map[k1].push_back(k2);
        map[k2].push_back(k1);
    }
    
    dfs(1);

    cout << num ;
    
    memset(visit, false, sizeof(visit));
    memset(map, false, sizeof(map));
    num =0;
    
    return 0;
}
