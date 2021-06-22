function solution(nums) {
    const amount = nums.length/2;
    const result = [...new Set(nums)].length;

    return amount > result ? result : amount
}
