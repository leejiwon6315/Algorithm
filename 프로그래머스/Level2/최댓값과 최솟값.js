function solution(s) {
    let tmp = s.split(' ').map(elem => parseInt(elem, 10));
    
    return `${Math.min(...tmp).toString()} ${Math.max(...tmp).toString()}`;
}
