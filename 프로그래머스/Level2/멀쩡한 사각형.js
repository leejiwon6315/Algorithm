function solution(w, h) {
    const g = gcd(w,h); // 최대공약수

    return (w*h)-(w+h-g);
}

function gcd(a, b){
    const tmp = a%b;
    
    if(tmp === 0){
        return b;
    }
    else return gcd(b, tmp);
}
