class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long a = n-1ll;
        return n && (!(n & (a)));
    }
};