function solution(s){
    let p = 0, y = 0; 
    
    s = s.toLowerCase();

    for(let i of s){
        if(i === 'p') p++;
        else if(i === 'y') y++; 
    }

    return p === y ? true : false;
}
