function solution(board, moves) {
    let result = [];
    let cnt = 0;
    
    for(let i=0; i<moves.length; i++){
         let peek = moves[i]-1;
        
        for(let j=0; j<board.length; j++){
            if( board[j][peek] === 0 ) continue;
            else{
                const lastLength = result.length <= 1 ? 0 : result.length-1;
                
                if(result[lastLength] === board[j][peek]){
                    board[j][peek] = 0;
                    result.splice(lastLength);
                    cnt += 2;
                }
                else{
                    result.push(board[j][peek]);
                    board[j][peek] = 0;
                }
                break;
            }
        }
    }
    
    return cnt;
}
