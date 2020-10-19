function solution(numbers) {
    let answer = [];
    let tmp = [];
    
    for(let i=0; i<numbers.length-1; i++){
        for(let j=i+1; j<numbers.length; j++){
            tmp.push(numbers[i] + numbers[j]);
        }
    }
    
    tmp.sort((a,b)=>a-b);
    
    for(let i=0; i<tmp.length; i++){
        answer.push(tmp[i]);
        
        while(tmp[i] == tmp[i+1]){
            i++;
        }
    }

    return answer;
}
