function solution(s) {
    const sLength = s.length;
    if(sLength !== 4 && sLength !== 6) return false;
    
    const tmp = s.split('').filter(elem => elem>=0 && elem <=9);
    return tmp.length === sLength ? true : false;
}
