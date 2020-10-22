#include<iostream>
#include<vector>
#include<queue>
#define size1 1001
#define size2 100001
using namespace std;

int INF = 100000000;
int n, m, start;
int z1, z2, z3, k1, k2;
vector<pair<int, int>> a[size1];
int d[size2];
void djstra(int start){
    for(int i = 1; i<=n; i++){
          d[i]=INF;
      } 
    d[start] = k1;    
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
    cout << d[k2];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    cin >> n >> m ;   
    for(int i=0; i<m; i++){
        cin >> z1 >> z2 >> z3;
        a[z1].push_back({z2,z3});
    }   
    cin >> k1 >> k2 ;  
    djstra(k1);   
    return 0;
}
