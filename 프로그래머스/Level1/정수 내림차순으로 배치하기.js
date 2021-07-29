function solution(n) {
    return parseInt(n.toString(10).split('').sort((a,b)=>b-a).join(''), 10);
}
