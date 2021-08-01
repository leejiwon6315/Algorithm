function solution(n, m) {
    
    const gcd = (n, m) => {
        const tmp = n%m;
        if(m === 0) return n;
        return gcd(m, tmp);
    }

    return [gcd(n, m), (n*m)/gcd(n, m)];
}

