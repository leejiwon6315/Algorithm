function solution(dartResult) {
    let now =0, before = 0, k = 0;
    let answer = 0;
    
    for(let i=0; i<dartResult.length; i++){
        if(dartResult[i] === '1' && dartResult[i+1] === '0'){
            k = 10;
            i++;
            continue;
        }
        else if(dartResult[i] <= '9' && dartResult[i] >= '0'){
            k = parseInt(dartResult[i], 10);
            continue;
        }
        
        if(dartResult[i] === 'S'){
            now = k;
            answer += now;
        }
        else if(dartResult[i] === 'D'){
            now = Math.pow(k, 2);
            answer += now;
        }
        else if(dartResult[i] === 'T'){
            now = Math.pow(k, 3);
            answer += now;
        }        
        
        if(dartResult[i+1] === '*'){
            answer += (now + before);
            now *= 2;
            i++;
        }
        else if(dartResult[i+1] === '#'){
            answer -= now;
            now = now * (-1);
            answer += now;
            i++;
        }
        
        before = now;
    }
    return answer;
}
