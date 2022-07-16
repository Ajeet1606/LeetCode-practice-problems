class Solution {
public:
    int M = 1000000007;
    int findPaths(int m, int n, int N, int r, int c) {
        
         vector<vector<vector<int>>> memo(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        
        return fun(m, n, N, r, c, memo);
    }
    
    
    int fun(int m, int n, int mxMove, int r, int c, vector<vector<vector<int>>> &memo){
        
        if(r==m or c==n or r<0 or c<0) return 1;
     
        if(mxMove == 0) return 0;
        
        if(memo[mxMove][r][c] != -1) return memo[mxMove][r][c]%M;
        
        int val = 0;
        val = (val + fun(m, n, mxMove-1, r, c-1, memo))%M;
        val = (val + fun(m, n, mxMove-1, r-1, c, memo))%M;
        val = (val + fun(m, n, mxMove-1, r, c+1, memo))%M;
        val = (val + fun(m, n, mxMove-1, r+1, c, memo))%M;
        
        memo[mxMove][r][c] = val%M;
        
        return memo[mxMove][r][c]%M;
    }
};