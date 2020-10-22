#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#define size1 1001
#define size2 10001
using namespace std;

int INF = 100000000;
int n, m, x, start;
int z1, z2, z3;

inline int Max(int a, int b) { return a > b ? a : b; }

vector<pair<int, int>> a[size1];
int d[size2];
int total[size2];

int djstra(int start, int end){
    for(int i = 1; i<=n; i++){
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
    total[start]=d[end];
    return d[end];
}
void djstra2(int start){
    for(int i = 1; i<=n; i++){
          d[i]=INF;
      }
    
    d[start] = 0;
    
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push({0, x});
    
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
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> x;
    
    for(int i=0; i<m; i++){
        cin >> z1 >> z2 >> z3;
        a[z1].push_back({z2,z3});
    }
    for(int i=1; i<=n; i++){
        djstra(i,x);
    }
    
    djstra2(x);
    int iMax = 0;
    for (int i = 1; i <= n; ++i){
        iMax = Max(iMax, d[i] + total[i]);
    }

    cout << iMax << endl;
    
    return 0;
}

