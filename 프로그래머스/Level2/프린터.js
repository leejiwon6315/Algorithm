function solution(answers) {
    let answer = [];
    let point = [0,0,0]; 
    const arr1 = [1,2,3,4,5];
    const arr2 = [2,1,2,3,2,4,2,5];
    const arr3 = [3,3,1,1,2,2,4,4,5,5];
    
    for(let i=0; i<answers.length; i++){
        if(arr1[i%arr1.length] === answers[i]) point[0]++;
        if(arr2[i%arr2.length] === answers[i]) point[1]++;
        if(arr3[i%arr3.length] === answers[i]) point[2]++;
    }
    let tmp = point;
    
    const max = Math.max.apply(null,tmp);
    
    for(let i=0; i<tmp.length; i++){
        if(max === point[i]) answer.push(i+1);
    }
    
    return answer;
}
