class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        vector<vector<long>>dp(n+1, vector<long>(n+1, 0));
        
        for(int unpicked = 0; unpicked<=n; unpicked++){
            for(int undelivered = unpicked; undelivered<=n; undelivered++){
                if(undelivered == 0 and unpicked == 0){
                    dp[unpicked][undelivered] =1;
                    continue;
                }
                if(unpicked > 0){
                    dp[unpicked][undelivered] += unpicked* dp[unpicked-1][undelivered];
                }
                dp[unpicked][undelivered] %= MOD;
                
                if(undelivered > unpicked){
                    dp[unpicked][undelivered] += (undelivered - unpicked)* dp[unpicked][undelivered-1];
                }
                dp[unpicked][undelivered] %= MOD;
            }
        }
        return dp[n][n];
    }
};