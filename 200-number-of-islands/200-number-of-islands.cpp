class Solution {
public:
    int rows, cols;
    void coverNext(vector<vector<char>>& grid, int i, int j){
        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j] != '1') return;
        grid[i][j] = '2';
        //left
        coverNext(grid, i, j-1);
        //right
        coverNext(grid, i, j+1);
        //top
        coverNext(grid, i-1, j);
        //bottom
        coverNext(grid, i+1, j);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    coverNext(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};