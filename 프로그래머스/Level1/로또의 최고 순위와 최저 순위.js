function solution(lottos, win_nums) {
    let cntZero = 0;
    let cntAnswer = 0;
    
    lottos.forEach(elem => { if(elem === 0) cntZero++ })
    
    if(cntZero === 6) return [1,6];
    else{
        for(let i=0; i<lottos.length; i++)
            for(let j=0; j<win_nums.length; j++)
                if(lottos[i] === win_nums[j]) cntAnswer++;
        
        if(cntAnswer < 2) cntAnswer = 1;
        return [7-(cntZero+cntAnswer), 7-cntAnswer];
    }

}
