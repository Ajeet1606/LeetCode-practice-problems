class Solution {
public:
    //memory optimized, iterative approach.
    int M = 1000000007;
    int kInversePairs(int n, int k) {
        int dp[2][1001] = { 1 };
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K){
                dp[N%2][K] = (dp[(N-1)%2][K] + (K>0? dp[N%2][K-1]: 0)) % M;
                if(K>=N){
                    dp[N%2][K] = (M + dp[N%2][K] - dp[(N-1)%2][K-N])%M;
                }
            }
        return dp[n%2][k];
    }
};