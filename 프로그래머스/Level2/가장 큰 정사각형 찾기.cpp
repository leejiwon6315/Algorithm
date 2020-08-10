#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int bWidth = board[0].size();
    int bHeight = board.size();

    for(int i=1; i<bHeight; i++){
        for(int j=1; j<bWidth; j++){
            
            if(board[i][j] == 1){
                board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1])) + 1;
                answer = max(answer, board[i][j]);
            }
            
        }
    }

    return answer * answer;
}
