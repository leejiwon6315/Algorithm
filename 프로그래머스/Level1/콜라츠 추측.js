function solution(num) {
    if(num === 1) return 0; 
    
    let k=1;
    while(num !== 1){
        if(k === 500) return -1;
        
        if(num%2 === 0) num /= 2;
        else num = num*3 + 1;
        
        if(num === 1) return k;
        k++;
    }
}
