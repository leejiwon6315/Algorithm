function solution(s) {  
    return s.split(' ').map(elem => elem.charAt(0).toUpperCase() + elem.substring(1).toLowerCase()).join(' ');
}
