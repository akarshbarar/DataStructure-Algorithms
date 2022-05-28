//!268. Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

//! Method One
var missingNumber = function(nums) {
    nums = nums.sort();
    let l = nums.length;
    if(nums[l-1] != l) return l;
    for(let i=0;i<l;i++){
        if(nums[i]-i != 0) {
            return i;
        }
    }
};