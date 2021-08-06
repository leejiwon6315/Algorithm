function solution(price, money, count) {
    let i = 1, cnt = 0;
    
    while(count--)
        cnt += price * (i++);

    return (money - cnt) >= 0 ? 0 : -(money - cnt);
}
