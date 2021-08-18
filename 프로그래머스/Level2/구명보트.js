function solution(people, limit) {
    people = people.sort((a,b) => b-a);
    
    let k = people.length-1, answer = 0;
    
    for(let i=0; i<=k; i++){
        if(people[i] + people[k] > limit)
            answer ++;
        else{
            answer ++;
            k--;
        }
    }
    return answer;
}
