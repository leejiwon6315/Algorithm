function solution(s) {
    let answer = [];
    s = s.slice(2, s.length-2).split('},{');
    
    const tmp = s.sort((a, b)=> a.length - b.length).map(elem => elem = elem.split(','));
    
    for(let i=0; i<tmp.length; i++)
        for(let j=0; j<tmp[i].length; j++)
            answer.push(parseInt(tmp[i][j], 10));

    return Array.from(new Set(answer));
}
