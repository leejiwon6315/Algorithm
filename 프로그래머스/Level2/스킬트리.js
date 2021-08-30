function solution(skill, skill_trees) {
    let answer = 0;
    
    skill_trees.forEach(elem => available(skill, elem) === true && answer ++);
    
    return answer;
}

function available(skill, tree) { 
    let hashMap = {}, k = 0;
    
    for(let i=0; i<skill.length; i++)
        hashMap = {...hashMap, [skill[i]] : i};
    
    for(let j=0; j<skill.length; j++){
        for(let i of tree){
            if(hashMap[i] === k)
                k++;
            
            else if(hashMap[i] > k)
                return false
            
            else continue;
        }
    }
    
    return true;
}
