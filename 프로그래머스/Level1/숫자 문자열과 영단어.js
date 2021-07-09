function solution(s) {
    const number = [/zero/g, /one/g, /two/g, /three/g, /four/g, /five/g, /six/g, /seven/g, /eight/g, /nine/g];
    
    for(let i=0; i<10; i++)
        s = s.replace(number[i], i);

    return Number(s);
}
