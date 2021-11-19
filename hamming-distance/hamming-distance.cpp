class Solution {
public:
    int hammingDistance(int x, int y) {
        // Doing XOR of both we'll get a number having set bits at positions where x and y differed, now we just need to count that.
        int ans = 0, n = x^y;
        // we know that right most set bit of n will be unset in n-1 and doing & of these two we turn off the right most set bit. In this process number of operations to turn of all of them will be there count. 
        while(n){
            n = n&n-1;
            ans++;
        }
        return ans;
    }
};