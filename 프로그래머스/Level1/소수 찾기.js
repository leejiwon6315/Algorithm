function solution(n) {
    let answer = 0;
    
    function primeNum(number){
        if(number === 2) return true;
        for(let i=2; i<=Math.floor(Math.sqrt(number)); i++){
            if(number%i === 0) return false;
        }
        return true;
    }

    for(let j=2; j<=n; j++)
        if(primeNum(j)) answer ++;
    
    return answer;
}
