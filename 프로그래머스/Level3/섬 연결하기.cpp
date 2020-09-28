#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortIsland(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int getParent(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int> &parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

bool find(vector<int> &parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    return a == b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, finIsNum = 0;
    vector<int> parent;
    
    sort(costs.begin(), costs.end(), sortIsland);
    
    for(int i=0; i<n; i++){
        parent.push_back(i);
    }
    
    for(int i=0; i<costs.size(); i++){
        if(!find(parent,costs[i][0],costs[i][1])){
            answer += costs[i][2];
            unionParent(parent,costs[i][0],costs[i][1]);
        }
    }
    
    return answer;
}
