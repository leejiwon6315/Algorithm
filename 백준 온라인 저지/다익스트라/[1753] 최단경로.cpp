#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#define size1 20001
#define size2 300001
using namespace std;
int INF = 100000000;
int v, e, start;
int z1, z2, z3;
vector<pair<int, int>> a[size1];
int d[size2];
void djstra(){
    for(int i = 1; i<=v; i++){
          d[i]=INF;
      }
    d[start] = 0;    
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push({0, start});    
    while(!pq.empty()){
        int current = pq.top().second;
        int fee = pq.top().first;
        pq.pop();
        if(d[current]<fee) continue;        
        for(int i = 0;i<a[current].size();i++){            
            int next = a[current][i].first;
            int nextfee = fee+a[current][i].second;           
            if(nextfee<d[next]){
                d[next] = nextfee;
                pq.push({nextfee, next});
            }
        }
    }
    for(int i = 1; i<=v; i++){
        if(d[i]==INF)cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e >> start;
    for(int i=0; i<e; i++){
        cin >> z1 >> z2 >> z3;
        a[z1].push_back({z2,z3});
    }  
    djstra();   
    return 0;
}

