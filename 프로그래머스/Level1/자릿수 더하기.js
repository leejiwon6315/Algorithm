function solution(n)
{
    return n.toString(10).split('').map(elem => parseInt(elem,10)).reduce((a,b)=> a+b);
}
