function solution(n, arr1, arr2) {
    let tmp1 = arr1.map(elem => elem.toString(2));
    let tmp2 = arr2.map(elem => elem.toString(2));
    let answer = [];
    
    for(let i=0; i<n; i++){
        while(tmp1[i].length !== n)
            tmp1[i] = '0' + tmp1[i];
        
        while(tmp2[i].length !== n)
            tmp2[i] = '0' + tmp2[i];
    }
    
    for(let i=0; i<n; i++){
        answer.push('');
        
        for(let j=0; j<n; j++){
            if(tmp1[i][j] === '1' || tmp2[i][j] === '1')
                answer[i] += '#';
            else answer[i] += ' ';
        }
    }
    
    return answer;
}
