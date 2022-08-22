class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        int cntOfOnes = 0, posOfOne = 0, shifted = 1;
        
        while(n > 0){
            if(n&1){
                posOfOne = shifted;
                cntOfOnes++;
            }
            n >>= 1;
            shifted++;
        }
        return cntOfOnes == 1 and posOfOne&1;
    }
};