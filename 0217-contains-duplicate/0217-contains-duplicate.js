/**
 * @param {number[]} nums
 * @return {boolean}
 */

/**
- sort the array
- if two consecutive elements are same, we found a duplicate.
- else false;

time: O(nlogn)
space: constant.
*/
var containsDuplicate = function(nums) {
    const len = nums.length;
    
    nums.sort();
    for(let idx = 0; idx < len-1; idx++){
        if(nums[idx] == nums[idx+1]) return true;
    }
    return false;
};