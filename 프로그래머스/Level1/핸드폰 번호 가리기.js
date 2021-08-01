function solution(phone_number) {
    let front = phone_number.slice(0, phone_number.length - 4);
    let back = phone_number.slice(front.length, phone_number.length);
    
    front = front.split('').map(elem => elem = "*").join('');
    return front+back;
}
