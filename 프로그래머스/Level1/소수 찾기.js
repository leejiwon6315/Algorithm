let PrimeArray = [];

function Eratos(n){
    for(let i=2; i<=n; i++)
        PrimeArray[i] = true;

    for(let i=2; i*i<=n; i++){
        if(PrimeArray[i]){
            for(let j=i*i; j<=n; j+=i)
                PrimeArray[j] = false;
        }
    }
}

function solution(n) {
    if(n === 2) return 1;
    let answer = 0;
    
    Eratos(n);
    
    for(let i=2; i<=n+1; i++)
        if(PrimeArray[i] == true) answer++;
    
    return answer;
}
