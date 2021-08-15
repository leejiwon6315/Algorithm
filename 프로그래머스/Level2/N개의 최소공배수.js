function solution(arr) {
    arr = arr.sort((a, b) => b-a);
    
    let i = 1;
    
    while(1){
        const LCM = arr[0] * i;
        const tmp = arr.filter(item => LCM%item === 0);
        
        if(tmp.length === arr.length) return LCM;
        else i++;
    }
}
