function solution(arr)
{
    var answer = [];

    for(var i=0; i<arr.length; i++){
        while(arr[i]===arr[i+1]){
            i++;
        }
        answer.push(arr[i]); 
    }
    
    return answer;
}
