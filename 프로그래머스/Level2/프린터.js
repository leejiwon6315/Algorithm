function solution(priorities, location) {
    let check = 0, cnt = 1;
    let hashMap = priorities.map((elem, index) => [elem, index]);
    
    while(hashMap.length > 0){
        const tmp = hashMap[0];
        
        for(let i=1; i<hashMap.length; i++){
            if(hashMap[i][0] > tmp[0]){
                hashMap = hashMap.slice(1, hashMap.length);
                hashMap.push(tmp);
                check = 0;
                break;
            }
            
            check = 1;
        }
        
        if(check === 1){
            if(tmp[1] === location) return cnt;
            cnt ++;
            hashMap = hashMap.slice(1, hashMap.length);
        }
    }
}
