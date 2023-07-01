class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0,-1}, {0, 1}};
    bool canReachToEnd(vector<vector<int>>&matrix, int row, int col, int cur_row, int cur_col){
        if(cur_row < 0 or cur_col < 0 or cur_row == row or cur_col == col) return false;
        if(matrix[cur_row][cur_col] != 0) return false;
        if(cur_row == row-1) return true;
        
        //operate on this cell, move to all 4 directions.
        matrix[cur_row][cur_col] = -1;
        
        for(int i=0; i<4; i++){
            int new_row = cur_row + dir[i][0];
            int new_col = cur_col + dir[i][1];
            if(canReachToEnd(matrix, row, col, new_row, new_col)) return true;
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int ans = 0, n = cells.size();
        
        int left = 0, right = n-1;
        while(left <= right){
            int mid = right - (right - left)/2;
            
            vector<vector<int>>matrix(row, vector<int>(col, 0));
            for(int i=0; i<=mid; i++){
                int r = cells[i][0]-1, c = cells[i][1]-1;
                matrix[r][c] = 1;
            }
        
            bool ok = false;
            for(int j = 0; j<col; j++){
                if(matrix[0][j] == 1) continue;
                
                if(canReachToEnd(matrix, row, col, 0, j)){
                    ok = true;
                    break;
                }
            }
            if(ok){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        return left;
    }
};