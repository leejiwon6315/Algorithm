#include <string>
#include <vector>

using namespace std;

int arr[1000][1000];

vector<int> solution(int n) {
    vector<int> answer; 
    
    int level = 1, i = 1;
    int y = 0, x = 0;

    while(1){
        int tmp = i;
        if(level == 1){
            while(y<n && x<n){
                if(arr[y][x] == 0){
                    arr[y][x] = i;
                    i++;
                    y++;
                }
                else{
                    y--;
                    x++;
                    level = 2;
                    break;
                }
            }  
            if(level == 1){
                y--;
                x++;
                level = 2;
            }
        }
        if(level == 2){
            while(y<n && x<n){
                if(arr[y][x] == 0){
                    arr[y][x] = i;
                    i++;
                    x++;
                }
                else{
                    x-=2;
                    y--;a
                    level = 3;
                    break;
                }
            }
            if(level == 2){
                x-=2;
                y--;
                level = 3;
            }
        }
        if(level = 3){
            while(y<n && x<n){
                if(arr[y][x] == 0){
                    arr[y][x] = i;
                    i++;
                    y--;
                    x--;
                }
                else{
                    y += 2;
                    x++;
                    level = 1;
                    break;
                }
            }  
        }
        if(i==tmp) break;
    
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            answer.push_back(arr[i-1][j]);
        }
    }
        
    return answer;
}
