function solution(n, lost, reserve) {
    n -= lost.length;
    
    for(let i=0, lLen=lost.length; i<lLen; i++){
        let index=reserve.indexOf(lost[i]);
        
        if(index !== -1){
            reserve.splice(index,1);
            lost.splice(i,1);
            n++;
            i--;
        }
    }
    
    for(let i=0, lLen=lost.length; i<lLen; i++){
        let front = reserve.indexOf(lost[i]-1);
        let back = reserve.indexOf(lost[i]+1);
        
        if(front !== -1){
            n++;
            reserve.splice(front,1);
        }
        else if(back !== -1){
            n++;
            reserve.splice(back,1);
        }
    }
    return n;
}
