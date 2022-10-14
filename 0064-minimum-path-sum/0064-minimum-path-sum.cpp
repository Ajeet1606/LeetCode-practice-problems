//Recursion
class Solution
{
    public:

       	//------------------------------Space optimized---------------
       	//					   O(rc) and O(c)

        int minPathSum(vector<vector < int>> &grid)
        {
            int rows = grid.size(), cols = grid[0].size();
            vector<int> prev(cols, 0);

            for (int i = 0; i < rows; ++i)
            {
                vector<int> curr(cols, 0);
                for (int j = 0; j < cols; ++j)
                {
                    if (i == 0 and j == 0) curr[j] = grid[0][0];
                    else
                    {
                        int up = 1e9;
                        if (i > 0)
                            up = prev[j];
                        int left = 1e9;
                        if (j > 0)
                            left = curr[j - 1];

                        curr[j] = grid[i][j] + min(up, left);
                    }
                }
                prev = curr;
            }

            return prev[cols - 1];
        }
};