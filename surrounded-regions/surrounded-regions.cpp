class Solution {
public:
    
    void checkThisCell(int i, int j, vector<vector<char>>& board){
        board[i][j] = '*';
        int row = board.size()-1;
        int col = board[0].size()-1;
        // top
        if(i-1 <= row && i>0 && j <= col && board[i-1][j]=='O')
            checkThisCell(i-1, j, board);
        // check it's right cell
        if(i <= row && j+1 <= col && board[i][j+1]=='O'){
            checkThisCell(i, j+1, board);
        }
        // check it's down cell
        if(i+1 <= row && j <= col && board[i+1][j]=='O'){
            checkThisCell(i+1, j, board);
        }
        //left
        if(i <= row && j>0 && j-1 <= col && board[i][j-1]=='O'){
            checkThisCell(i, j-1, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int col = board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'){
                    // first check if it's on border
                    if(i==0 || j==0 || i==rows-1 || j==col-1)
                    checkThisCell(i, j, board);  
                }
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};