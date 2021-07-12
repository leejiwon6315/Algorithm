function solution(progresses, speeds) {
    let answer = [];
    let k=0;
    
    while(1){
        let cnt = 0;
        for(let i=0; i<speeds.length; i++)
            progresses[i] += speeds[i];
        
        while(progresses[k] >= 100){
            cnt ++;
            k ++;
        }
        
        if(cnt > 0) answer.push(cnt);  
        if(k >= progresses.length) break;
    }

    return answer;
}
