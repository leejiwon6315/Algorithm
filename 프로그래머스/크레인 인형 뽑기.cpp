#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
        
    for(int i=0; i<moves.size(); i++){
        for(int j=0; j<board.size(); j++){

            if(board[j][moves[i]-1] != 0 ){
                int doll = board[j][moves[i]-1];
                
                if(!basket.empty()){
                    if (basket.top() == doll){
                        answer +=2;
                        basket.pop();
                    }
                    else{
                        basket.push(doll);
                    }
                }
                else basket.push(doll);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}
