class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        int cur = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(solve(i, j, row, col, board, cur, word)) return true;
            }
        }
        return false;
    }
    
    bool solve(int r, int c, int row, int col, vector<vector<char>>& board, int cur, string &word){
        if(cur == word.length()) return true;
        
        if(r < 0 or r >= row or c < 0 or c >= col) return false;
        if(board[r][c] == '!') return false;
        if(board[r][c] != word[cur]) return false;
        
        //current values match, so we check all 4 directions of grid for next char of word.
        // cout<<board[r][c]<<' '<<r<<' '<<c<<endl;
        char ch = board[r][c];
        board[r][c] = '!';
        
        bool top = solve(r-1, c, row, col, board, cur+1, word);
        bool down = solve(r+1, c, row, col, board, cur+1, word);
        bool left = solve(r, c-1, row, col, board, cur+1, word);
        bool right = solve(r, c+1, row, col, board, cur+1, word);
        // cout<<board[r][c]<<' '<<"top "<<top<<"down "<<down<<"left "<<left<<"right "<<right<<endl;
       
        board[r][c] = ch;
        return top or down or left or right;
    }
};