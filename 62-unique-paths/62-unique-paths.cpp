class Solution {
public:
    //bottom up dp
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m, vector<int>(n, 0));
        for(int i = m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){
                if(i == m-1 and j== n-1)
                    memo[i][j] = 1;
                else{
                    if(i+1 < m)
                        memo[i][j] += memo[i+1][j];
                    if(j+1 < n)
                        memo[i][j] += memo[i][j+1];
                }
            }
        }
        return memo[0][0];
    }
};