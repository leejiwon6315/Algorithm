#include<iostream>
#include<vector>
#include<queue>
#define max 130

using namespace std;

int INF = 100000000;
int n;
int map[max][max];
int d[max][max];
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
priority_queue< pair<int, pair<int, int>> > pq;

void djstra(){
    d[1][1]=map[1][1];
    pq.push(make_pair(-d[1][1],make_pair(1,1)));
    
    while(!pq.empty()){
        int point= -pq.top().first;
        int x=pq.top().second.second;
        int y=pq.top().second.first;
        pq.pop();
        
        for(int i=0; i<4; i++){
            int xx=x+nx[i];
            int yy=y+ny[i];
            
            if(xx<1 || xx>n || yy<1 || yy>n) continue;
            
            int next=point+map[yy][xx];
            
            if(next<d[yy][xx]){
                d[yy][xx]=next;
                pq.push(make_pair(-next, make_pair(yy,xx)));
            }
        }
    }

}

int main(void){
    int num=1;
    
    while(1){
        cin >> n ;
        if(n==0) break;
        
        fill(&d[0][0], &d[129][130], INF);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> map[i][j];
            }
        }
        
        djstra();
    
        cout << "Problem " << num <<": " << d[n][n] << endl;
        num++;
    }
    return 0;
}

