function solution(scores) {
    let answer = '', number = 0;
    
    for(let i=0; i<scores.length; i++){
        let tmpArr = [];
        
        for(let j=0; j<scores.length; j++)
            tmpArr.push(scores[j][i]);
        
        const maxNum = Math.max(...tmpArr);
        const minNum = Math.min(...tmpArr);
        
        if(maxNum !== minNum){
            const maxCheck = tmpArr.filter(e => e === maxNum);
            const minCheck = tmpArr.filter(e => e === minNum);
            
            if((tmpArr[i] === maxNum && maxCheck.length === 1) || (tmpArr[i] === minNum && minCheck.length === 1))
                tmpArr = tmpArr.filter(e => e !== tmpArr[i]);
        }

        if(tmpArr.length > 1) number = tmpArr.reduce((a,b)=> a+b)/tmpArr.length;
        else number = tmpArr[0];
        
        if(number >= 90) answer += 'A';
        else if(number >= 80 && number < 90) answer += 'B'; 
        else if(number >= 70 && number < 80) answer += 'C'; 
        else if(number >= 50 && number < 70) answer += 'D'; 
        else if(number < 50) answer += 'F';
    }
    
    return answer;
}
