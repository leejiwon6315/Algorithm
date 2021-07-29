function solution(n) {
    return n.toString(10).split('').reverse().map(elem => parseInt(elem, 10));
}
