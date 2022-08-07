class Solution {
public:
    bool validPartition(vector<int>& arr) {
        int n = arr.size();
        //store results
        vector<bool>dp(n+1, false);
        
        dp[0] = true;
        for(int i=2; i<=n; i++){
            //if prev 2 elements exist, check condition
            if(i>=2){
                if(arr[i-1] == arr[i-2]){
                    dp[i] = dp[i] or dp[i-2];
                }
            }
            //if prev 3 exist check this too.
            if(i>=3){
                if(arr[i-1] == arr[i-2] and arr[i-2] == arr[i-3]){
                    dp[i] = dp[i] or dp[i-3];
                }
                else if(arr[i-1] == arr[i-2]+1 and arr[i-2] == arr[i-3]+1){
                    dp[i] = dp[i] or dp[i-3];
                }
            }
        }
        return dp[n];
    }
};