//Tabulation
class Solution {
public:    
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n, 0);
        dp[0] = arr[0];
        
        for(int i=1; i<n; i++){
            int take = arr[i];
            if(i>1) take += dp[i-2];
            
            int skip = dp[i-1];
            
            dp[i] = max(take, skip);
            cout<<dp[i];
        }    
        
        return dp[n-1];
    }
};