function solution(nums) {
    let answer = 0;
    
    for(let q=0; q<nums.length-2; q++)
        for(let w=q+1; w<nums.length-1; w++)
            for(let e=w+1; e<nums.length; e++)
                if(findPrimeNumber(nums[q], nums[w], nums[e])) answer ++;
    
    return answer;
}

function findPrimeNumber(n1, n2, n3){
    const sum = n1 + n2 + n3;
    
    for(let i=2; i<=Math.sqrt(sum); i++)
        if(sum%i === 0) return false;
        
    return true;
}
