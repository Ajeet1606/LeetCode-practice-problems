class Solution {
public:
    bool isPowerOfFour(int n) {
        
        double res= log(n)/log(4);
        res = res - floor(res);
        return res == 0;
    }
};