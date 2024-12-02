/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

/*
create a map to store freq of string1
reduce the freq of chars by traversing string2
if map contains anymore char with >0 freq, there's a mismatch.
*/
var isAnagram = function(s, t) {
    const len1 = s.length, len2 = t.length;
    
    const frequency_map = new Map();
    for(let i=0; i<len1; i++){
        if(frequency_map.has(s[i])){
            const prevValue = frequency_map.get(s[i]);
            frequency_map.set(s[i], prevValue+1);
        }else{
            frequency_map.set(s[i], 1);
        }
    }
    
    for(let j=0; j<len2; j++){
        if(frequency_map.has(t[j])){
            const prevValue = frequency_map.get(t[j]);
            frequency_map.set(t[j], prevValue-1);
        }else{
            return false;
        }
    }
    
    
    for(const value of frequency_map.values()){
        if(value != 0) return false;
    }
    return true;
};