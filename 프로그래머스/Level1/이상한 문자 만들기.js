function solution(s) {
    let answer = s.split(' ')
    
    for(let i=0; i<answer.length; i++)
        answer[i] = answer[i].split('').map((elem, index) => index%2 === 0 ? elem.toUpperCase() : elem.toLowerCase()).join('');
    
    return answer.join(' ');
}
