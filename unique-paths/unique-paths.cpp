class Solution {
    
public:    
    
    int helper(int m, int n, int i, int j, vector<vector<int>> &memo){
        if(i >= m || j >= n)
            return 0;
        else if(i == m-1 || j == n-1)
            return 1;
        else if(memo[i][j]>0)
            return memo[i][j];
        else{
            memo[i][j] = helper(m, n, i+1, j, memo) + helper(m, n, i, j+1, memo);
            return memo[i][j];
        }
    }
    
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return helper(m, n, 0, 0, memo);
        
    }
};