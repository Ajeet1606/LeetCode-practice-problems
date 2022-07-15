class Solution {
public:
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, fun(grid, i, j));
            }
        }
        return ans;
    }
    
    
    int fun(vector<vector<int>>& grid, int i, int j){
        //if we're going out of grid or grid value is 0, ans = 0. 
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j] == 0) return 0;
        //update grid value to avoid future repetition.
        grid[i][j] = 0;
        //ans will be 1 for current + others from all 4 sides.
        return 1+ fun(grid, i-1, j) + fun(grid, i+1, j) +fun(grid, i, j-1) + fun(grid, i, j+1);
    }
};