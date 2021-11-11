class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1, prefix = 0;
        for(auto &x: nums){
            prefix += x;
            if(prefix < 0) ans = max(ans, abs(prefix)+1);
        }
        return ans;
    }
};