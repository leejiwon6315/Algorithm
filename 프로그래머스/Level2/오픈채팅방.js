function solution(record) {
    let answer = [], mapSet= {};
    const tmp = record.map(elem => elem.split(' '));
    
    for(let i=0; i<tmp.length; i++){
        if(tmp[i].length === 3)
            mapSet[tmp[i][1]] = tmp[i][2];
    }
    
    for(let i=0; i<tmp.length; i++){
        if(tmp[i][0] === 'Enter') answer.push(`${mapSet[tmp[i][1]]}님이 들어왔습니다.`);
        else if(tmp[i][0] === 'Leave') answer.push(`${mapSet[tmp[i][1]]}님이 나갔습니다.`);
    }
    
    return answer;
}
