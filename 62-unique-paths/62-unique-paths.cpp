class Solution {
public:
    //bottom up dp
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m, vector<int>(n, 0));
        memo[m-1][n-1] = 1;
        int ans = getUniquePaths(0, 0, m, n, memo);
        return ans;
    }
    
    int getUniquePaths(int i, int j, int m, int n, vector<vector<int>>&memo){
        if(i>= m or j>=n)
            return 0;
        
        if(memo[i][j] != 0)
            return memo[i][j];
        
        return memo[i][j] = getUniquePaths(i+1, j, m, n, memo) + getUniquePaths(i, j+1, m, n, memo);
    }
};