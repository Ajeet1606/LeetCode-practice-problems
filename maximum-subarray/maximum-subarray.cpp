class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for(auto &x: nums){
            sum += x;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};