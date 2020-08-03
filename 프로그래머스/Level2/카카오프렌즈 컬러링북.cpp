#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool check[100][100];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int bfs(int m, int n, int x, int y, vector<vector<int>> map){
    
    int size = 1;
    int color = map[x][y];
    queue<pair<int, int>> q;
    
    q.push(make_pair(x, y));
    check[x][y] = true;
    
    while(!q.empty()){
        
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                
                if(!check[nx][ny] && map[nx][ny] == color){
                    
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    size ++;
                }
            }
  
        }
    }
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            check[i][j] = false;
        }
    }
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            
            if(!check[i][j] && picture[i][j]){
                int size = bfs(m, n, i, j, picture);
                if(size > max_size_of_one_area) max_size_of_one_area = size;
                number_of_area ++;
            }
            
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
