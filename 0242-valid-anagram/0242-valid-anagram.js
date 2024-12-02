/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(first_string, second_string) {
    if(first_string.length != second_string.length) return false;
    
    const sorted_string1 = first_string.split('').sort().join('');
    const sorted_string2 = second_string.split('').sort().join('');
    
    return sorted_string1 == sorted_string2;
};