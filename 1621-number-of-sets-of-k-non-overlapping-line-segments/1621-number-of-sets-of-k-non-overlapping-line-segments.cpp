class Solution {
public:
    
    const int MOD = 1e9+7;
    int dp[1002][1002];
    int prefix[1002][1002];
    
    int mod(int a){
        return (a%MOD + MOD)%MOD;
    }
    
    int add(int a, int b){
        return mod(mod(a) + mod(b));
    }
    
    int multiply(int a, int b){
        return mod(mod(a) * mod(b));
    }
    
    
    int doPrefix(int n, int k){
        if(n < 2) return 0;
        
        if(prefix[n][k] != -1) return prefix[n][k];
        return prefix[n][k] = add(doPrefix(n-1, k), ok(n, k));
    }
    
    int ok(int n, int k){
        if(k == 1){
            return dp[n][k] = (n*(n-1))/2;
        }
        
        if(k == n-1){
            return 1;
        }
        
        if(k > n-1) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int total = 0;
        
        total = add(total, ok(n-1, k));
        
        
        total = add(total, doPrefix(n-1, k-1));
        
        return dp[n][k] = total;
    }
    
    
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(prefix, -1, sizeof(prefix));
        return ok(n, k);
    }
};