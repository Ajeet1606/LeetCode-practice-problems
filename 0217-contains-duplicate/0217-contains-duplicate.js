/**
 * @param {number[]} nums
 * @return {boolean}
 */

/**
- traverse array
- check if cur element is in set,
    - yes, found duplicate
    - no, push element in set
- repeat.
- when control goes out of array, means no duplicate found.
*/
var containsDuplicate = function(nums) {
    const len = nums.length;
    
    const is_seen = new Set();
    for(let cur = 0; cur < len; cur++){
        if(is_seen.has(nums[cur])){
            return true;
        }else{
            is_seen.add(nums[cur]);
        }
    }
    return false;
};