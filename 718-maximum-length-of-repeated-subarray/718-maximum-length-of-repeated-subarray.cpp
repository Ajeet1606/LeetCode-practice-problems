class Solution
{
    public:	//DP n1*n2*min(n1, n2)
        int findLength(vector<int> &arr1, vector<int> &arr2){
            int n1 = arr1.size(), n2 = arr2.size();
            int dp[n1 + 1][n2 + 1];
            memset(dp, -1, sizeof dp);
            int ans = 0;
            for (int i = 0; i < n1; i++){
                for (int j = 0, len = 0; j < n2; j++){
                    if (dp[i][j] == -1){
                        while (i + len < n1 and j + len < n2 and arr1[i + len] == arr2[j + len])
                            len++;
                        
                        while (len)
                            dp[i + len][j + len] = len--;
                    }

                    ans = max(ans, dp[i][j]);
                }
            }
            return ans;
        }
};