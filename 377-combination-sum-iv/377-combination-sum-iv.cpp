class Solution {
public:
    int combinationSum4(vector<int>& arr, int target) {
        vector<int>dp(target+1, -1);
        return solve(arr, target, arr.size(), dp);
    }
    
    int solve(vector<int>arr, int target, int len, vector<int>&dp){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i=0; i<len; i++){
            ans += solve(arr, target - arr[i], len, dp);
        }
        
        return dp[target] = ans;
    }
};