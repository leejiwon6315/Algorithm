function solution(N, stages) {
    let tmpArr = new Array(N+1).fill(0);
    const len = stages.length;
    
    stages = stages.sort((a,b) => a-b);
    
    for(let i=0; i<len; i++) tmpArr[stages[i]-1] ++;

    let user = len;
    for(let i=0; i<N+1; i++){
        const unclearedUser = tmpArr[i];
        tmpArr[i] = [i+1, unclearedUser/user];
        user -= unclearedUser;
    }
    tmpArr = tmpArr.slice(0, tmpArr.length-1).sort((a, b)=> b[1]-a[1]);

    return tmpArr.map(e => e[0]);
}
