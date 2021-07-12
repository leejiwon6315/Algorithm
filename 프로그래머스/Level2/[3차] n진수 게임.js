function solution(n, t, m, p) {
    let answer = '';
    let tmp = "";
    
    for(let i=0; i<t*m; i++)
        tmp += i.toString(n);

    for(let i=0; i<t*m; i++)
        if(i%m === p-1) answer += tmp[i];

    return answer.toUpperCase();
}
