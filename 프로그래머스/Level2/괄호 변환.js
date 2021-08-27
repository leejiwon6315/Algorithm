function solution(p) {
    if(p === "") return p; 
    let u = '', v = '', left = 0, right = 0;

    for(let i = 0; i<p.length; i++){
        p[i] === '(' ? left ++ : right ++;

        if(left === right){ 
            u = p.slice(0, i+1);
            v = p.slice(i+1, p.length); 

            if(checkRightString(u)) return u + solution(v);
            else return `(${solution(v)})${u.slice(1, u.length-1).split('').map(elem => elem === '(' ? ')' : '(').join('')}`;
        }
    }
}

function checkRightString(str){
    const stack = [];

    for(let i of str){
        if(i === '(') stack.push(i);
        else{
            if(stack.length <= 0) return false
            else stack.pop();
        }
    }

    return true;
}
