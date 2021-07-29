function solution(s, n) {
    let answer = s.split('');
    let result = "";
    
    for(let i=0; i<answer.length; i++){
        if(answer[i] === ' '){
            result += " ";
            continue;
        }
        else{
            const ascii = parseInt(answer[i].charCodeAt(0), 10);
            const tmp = (ascii >= 65 && ascii <= 90) ? 65 : 97;
            
            result += String.fromCharCode(tmp + (ascii-tmp+n)%26);
        }
    }
    return result;
}
