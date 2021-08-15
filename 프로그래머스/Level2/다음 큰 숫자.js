function solution(n) {
    let nextN = n+1;
    
    while(1){
        const nLength = n.toString(2).split('').filter(item => item === '1').length;
        const nextNLength = nextN.toString(2).split('').filter(item => item === '1').length;
        
        if(nLength === nextNLength) return nextN;
        else nextN ++;
    }
}
