//Recursion
class Solution
{
    public:

       	//------------------------------Tabulation--------------------------
       	//					   O(rc) and O(rc)

        int minPathSum(vector<vector < int>> &grid)
        {
            int rows = grid.size(), cols = grid[0].size();
            vector<vector < int>> dp(rows, vector<int> (cols, 0));

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (i == 0 and j == 0) dp[i][j] = grid[0][0];
                    else
                    {
                        int up = 1e9;
                        if (i > 0)
                            up = dp[i - 1][j];
                        int left = 1e9;
                        if (j > 0)
                            left = dp[i][j - 1];

                        dp[i][j] = grid[i][j] + min(up, left);
                    }
                }
            }

            return dp[rows - 1][cols - 1];
        }
};