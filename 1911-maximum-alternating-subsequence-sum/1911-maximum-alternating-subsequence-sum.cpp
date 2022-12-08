class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        long long dp[n][2];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = arr[0];
        
        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - arr[i]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }    
};