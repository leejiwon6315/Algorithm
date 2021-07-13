function solution(s) {
    if(s.length === 1) return 1;
    let answer = s.length;
    
    for(let i=0; i<s.length/2; i++){
        let len = i+1, cnt = 1;
        let str = "";
        
        for(let j=0; j<s.length; j+=len){
            const compStr = s.substr(j, len);
            const compedStr = s.substr(j+len, len);
            
            if(compStr === compedStr) cnt ++;
            else{
                if(cnt > 1) str += cnt.toString() + compStr;
                else str += compStr;
                cnt = 1;
            }
        }
        answer = Math.min(answer, str.length);
    }
    return answer;
}
