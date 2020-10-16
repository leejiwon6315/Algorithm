function solution(participant, completion) {
    
    participant.sort();
    completion.sort();
    
    for(let i=0, len=completion.length; i<len; i++){
        if(completion[i] !== participant[i]){
            return participant[i];
        }
    }
    
    return participant[participant.length-1];
}
