function solution(n) {
    const tmp = Math.sqrt(n);
    if(tmp%1 > 0) return -1;
    
    return Math.pow(tmp+1, 2);
}
