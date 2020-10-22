#include <string>
#include <vector>
#include <queue>

using namespace std;

void clearQueue(queue<int> &q){
    queue<int> empty;
    swap(empty, q);
}

bool check[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    queue<int> q;
    queue<int> tmp;
    
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i=0; i<edge.size(); i++){
            if(now == edge[i][0] || now == edge[i][1]){
                if(now == edge[i][1] && !check[edge[i][0]]){
                    check[edge[i][0]] = true;
                    tmp.push(edge[i][0]);
                }
                else{
                    if(!check[edge[i][1]]){
                        check[edge[i][1]] = true;
                        tmp.push(edge[i][1]);
                    }
                }
                edge.erase(edge.begin()+i);
                i--;
            }
        }
        if(q.empty()){
            q=tmp;
            if(!tmp.empty()){
                answer = tmp.size();
            }
            clearQueue(tmp);
        }
    }
    
    return answer;
}
