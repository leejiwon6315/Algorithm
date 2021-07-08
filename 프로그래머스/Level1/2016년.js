function solution(a, b) {
    let answer = '';
    let tmp = 0;
    
    const month = ["FRI","SAT","SUN","MON","TUE","WED","THU"];
    const day = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    for(let i=0; i<a-1; i++) tmp += day[i];
    tmp += b-1;
    
    return month[tmp%7];
}
