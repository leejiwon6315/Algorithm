function solution(new_id) {
    let tmp = new_id.toLowerCase();	// 1단계
    let level = 2;
    let result = "";
    
    const filterEng = /[a-z]/;
    const filterSpec = /[-_.]/;
    const filterNum = /[0-9]/;
    
    if(level === 2){ // 2단계
        for(let i=0; i<tmp.length; i++)
            if(filterEng.test(tmp[i]) || filterSpec.test(tmp[i]) || filterNum.test(tmp[i]))
                result += tmp[i];
        level ++;
        tmp = "";
    }
    
    if(level === 3){ // 3단계
        let dot = "";
        
        for(let i=0; i<result.length; i++){
            if(result[i] === ".") dot = ".";
            else{
                if(dot === "."){
                    tmp += dot + result[i];
                    dot = "";
                }
                else tmp += result[i];
            }
        }
        level ++;
        result = "";
    }
    
    if(level === 4){ // 4단계
        if(tmp[0] === ".") result = tmp.substr(1,tmp.length-1);
        else if(tmp[tmp.length]-1 === ".") result = tmp.substr(0, tmp[tmp.length]-2);
        else result = tmp;
        
        level ++;
        tmp = "";
    }
    
    if(level === 5){ // 5단계
        if(result === "") result = "aaa";
        level ++;
    }
    
    if(level === 6){ // 6단계
        if(result.length >= 16 ){
            if(result[14] === ".") tmp = result.substr(0,14);
            else tmp = result.substr(0,15);        
        }
        else tmp = result;
        level ++;
    }
    
    if(level === 7){ // 7단계
        if(tmp.length <= 2)
            while(result.length < 3)
                result += tmp[tmp.length-1];
        else result = tmp;
    }
    
    return result;
}
