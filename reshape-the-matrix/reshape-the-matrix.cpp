class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m*n != r*c)
            return mat;
        int row = 0, col = 0;
        vector<vector<int>>ans(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans[i][j] = mat[row][col++];
                if(col == n){
                    col %= n, row++;
                }
            }
        }
        return ans;
    }
};