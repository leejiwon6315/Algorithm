function solution(n) {
    let answer = 1;
    
    for(let i=1; i<=n-1; i++){
        let sum = i;
        
        for(let j=i+1; j<=n; j++){
            if(sum === n){
                answer ++;
                break;
            }
            else if(sum > n) break;
            
            sum += j;
        }
    }
    return answer;
}
