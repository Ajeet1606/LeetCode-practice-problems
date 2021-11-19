class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32>b1(x&y);
        bitset<32>b2(x|y);
        // count set bits in and of two numbers
        int r1 = b1.count();
        // count set bits in or of two numbers
        int r2 = b2.count();
        return abs(r1-r2);
    }
};