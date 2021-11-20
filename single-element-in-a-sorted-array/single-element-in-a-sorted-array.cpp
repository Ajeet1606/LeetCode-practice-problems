class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorOfAll = 0;
        for(auto &i: nums)
            xorOfAll = xorOfAll xor i;
        return xorOfAll;
    }
};