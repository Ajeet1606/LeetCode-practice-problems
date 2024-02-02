class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.');
        vector<string>board(n, s);
        
        solve(0, n, board, ans);
        return ans;
    }
    
    void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        //try to place on each row
        for(int row = 0; row < n; row++){
            if(canPlace(row, col, board)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    
    bool canPlace(int cur_row, int cur_col, vector<string>&board){
        int n = board.size();
        
        //since we're moving from left to right, top to bottom, so we only need to check left, top-left, left-bottom as in other directions there can't be any queen.
        
        //top left: diagonal
        int row = cur_row, col = cur_col;
        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row--, col--;
        }
        
        //left side
        row = cur_row, col = cur_col;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        //left-bottom diagonal.
        row = cur_row, col = cur_col;
        while(row < n and col >= 0){
            if(board[row][col] == 'Q') return false;
            row++, col--;
        }
        
        return true;
    }
};