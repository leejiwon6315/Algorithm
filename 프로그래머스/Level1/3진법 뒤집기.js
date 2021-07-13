function solution(n) {
    let answer = 0;
    let tmp = n.toString(3);

    for(let i=0; i<tmp.length; i++){
        if(tmp[i] === 0) continue;
        answer += tmp[i]*Math.pow(3, i);
    }
    
    return answer;
}
