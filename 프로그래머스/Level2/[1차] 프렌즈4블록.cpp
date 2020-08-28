#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        vector<string> copyBoard = board;
        int copyAnswer = answer;
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j] != 'x' && board[i][j] == board[i+1][j] 
                   && board[i+1][j] == board[i][j+1] 
                   && board[i][j+1] == board[i+1][j+1]){
                    
                    if(copyBoard[i][j] != 'x') answer ++;
                    if(copyBoard[i][j+1] != 'x') answer ++;
                    if(copyBoard[i+1][j] != 'x') answer ++;
                    if(copyBoard[i+1][j+1] != 'x') answer ++;

                    copyBoard[i][j] = 'x';
                    copyBoard[i][j+1] = 'x';
                    copyBoard[i+1][j] = 'x';
                    copyBoard[i+1][j+1] = 'x';
                }
            }
        }

        if(copyAnswer == answer) break;
        board = copyBoard;
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(board[i][j] == 'x'){
                    for(int k=i-1; k>=0; k--){
                        if(board[k][j] != 'x'){
                            swap(board[i][j], board[k][j]);
                            break;
                        }
                    }
                }
            }
        }
    }    
    return answer;
}
