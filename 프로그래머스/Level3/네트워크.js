function solution(n, computers) {
    var answer = 0;
    let tmp = Array.from({length: 200}, () => false);
   
    function dfs(start){
        tmp[start] = true;
        
        for(let i=0; i<n; i++){
            if(!tmp[i] && computers[start][i] === 1){
                dfs(i);
            }    
        }
    }
    
    for(let j=0; j<n; j++){
        if(!tmp[j]){
            dfs(j);
            answer ++;
        }
    }
    
    return answer;
}
