class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        return __gcd(min, max);
    }
};