class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1) return 0;
        grid[0][0] = 1;
        
        //first row
        for(int i=1; i<row; i++){
            grid[i][0] = (grid[i][0]==0 && grid[i-1][0]==1) ? 1: 0;
        }
        
        // first col
        for(int i=1; i<col; i++){
            grid[0][i] = (grid[0][i]==0 && grid[0][i-1]==1) ? 1: 0;
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(grid[i][j]==0)
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                else
                    grid[i][j] = 0;
            }
        }
        return grid[row-1][col-1];
    }
};