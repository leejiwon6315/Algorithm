function solution(s) {
    return ((s.length%2) === 1)?
        s[Math.ceil(s.length/2)-1]:
        s[Math.ceil(s.length/2)-1] + s[Math.ceil(s.length/2)]
}
