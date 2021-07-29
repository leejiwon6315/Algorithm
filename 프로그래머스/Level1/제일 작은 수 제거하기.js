function solution(arr) {
    if(arr.length === 1) return [-1];
    
    const minNum = Math.min(...arr);

    return arr.filter(elem => elem != minNum);
}
