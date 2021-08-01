function solution(x) {
    let tmp = 0;
    const arr = x.toString(10).split('');
    
    for(let i of arr) tmp += parseInt(i,10);
    
    return x%tmp === 0 ? true : false;
}
