/**
 * @param {number[]} nums
 * @return {boolean}
 */

/**
- inset the array elements in a set
- if set size is equal to array length, no duplicates
- else there's a duplicate.

time: O(n)
space: O(n).
*/
var containsDuplicate = function(nums) {
    const len = nums.length;
    
    const my_set = new Set(nums);
    if(my_set.size == nums.length) return false;
    return true;
};