function solution(d, budget) {
    let answer = 0, tmp = 0;
    
    d = d.sort((a,b) => a-b);
    for(let i=answer; i<d.length; i++){
        if(tmp + d[answer] > budget) break;
        tmp += d[answer++];
    }
    
    return answer;
}
