class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.');
        vector<string>board(n, s);
         vector<int>leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, n, board, ans, leftrow, upperDiagonal, lowerDiagonal);
        return ans;
    }
    
    void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans, vector<int>&leftrow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        //try to place on each row
        for(int row = 0; row < n; row++){
            if(leftrow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col+1, n, board, ans, leftrow, upperDiagonal, lowerDiagonal);
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }
};