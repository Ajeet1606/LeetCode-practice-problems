//Recursion
class Solution {
public:
    
    //------------------------------Memoization--------------------------------------------
//					   O(rc) and O(rc + path length)

int fun(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
	//Base Case
	if (i == 0 and j == 0) return grid[0][0];
	if (i < 0 or j < 0) return 1e9;

	//already calculated
	if(dp[i][j] != -1) return dp[i][j];

	//let's find out
	int up = fun(i-1, j, grid, dp);	//go up
	int left = fun(i, j-1, grid, dp);	//go left

	//save and return
	return dp[i][j] = grid[i][j] + min(up, left);
}
    
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols, -1));
        return fun(rows-1, cols-1, grid, dp);
    }
};