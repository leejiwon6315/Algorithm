function solution(word) {
    const arr = ['A', 'E', 'I', 'O', 'U'];
    let d = 781, answer = 0;
    
    for(let i of word){
        for(let j=0; j<arr.length; j++){
            if(i === arr[j]){
                answer += 1 + d * j;
                break;
            }
        }
        
        d = parseInt((d-1)/5);
    }
    
    return answer;
}
