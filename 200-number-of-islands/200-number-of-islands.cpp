class Solution {
public:
    int rows, cols;
    void coverNext(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&seen){
        //left
        if(j > 0){
            if(grid[i][j-1] == '1' and seen[i][j-1] == false){
                seen[i][j-1] = true;
                coverNext(grid, i, j-1, seen);
            }
        }
        //right
        if(j < cols-1){
            if(grid[i][j+1] == '1' and seen[i][j+1] == false){
                seen[i][j+1] = true;
                coverNext(grid, i, j+1, seen);
            }
        }
        //top
        if(i > 0){
            if(grid[i-1][j] == '1' and seen[i-1][j] == false){
                seen[i-1][j] = true;
                coverNext(grid, i-1, j, seen);
            }
        }
        //bottom
        if(i < rows-1){
            if(grid[i+1][j] == '1' and seen[i+1][j] == false){
                seen[i+1][j] = true;
                coverNext(grid, i+1, j, seen);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>>seen(rows, vector<bool>(cols, 0));
        
        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(seen[i][j] == true or grid[i][j] == '0') continue;
                seen[i][j] = true;
                coverNext(grid, i, j, seen);
                ans++;
            }
        }
        return ans;
    }
};