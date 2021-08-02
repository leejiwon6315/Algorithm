function solution(n) {
    if(n <= 1) return n;
    let answer = [0, 1];
    
    for(let i=2; i<=n; i++)
        answer.push((answer[i-2] + answer[i-1])%1234567);
    
    return answer[n];
}
