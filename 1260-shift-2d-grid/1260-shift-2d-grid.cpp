class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        
        for(int l=0; l<k; l++){
        int temp = grid[rows-1][cols-1];
        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                if(i==0 and j==0){
                    grid[i][j] = temp;
                }
                else if(j==0){
                    grid[i][j] = grid[i-1][cols-1];
                }
                else{
                    grid[i][j] = grid[i][j-1];
                }
            }
        }
        }
        return grid;
    }
};