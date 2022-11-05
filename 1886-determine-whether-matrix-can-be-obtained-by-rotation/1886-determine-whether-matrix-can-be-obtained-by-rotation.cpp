class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool>c(4, true);
        int n = mat.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(mat[i][j] != target[i][j]) c[0] = false;
                if(mat[i][j] != target[j][n-i-1]) c[1] = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) c[2] = false;
                if(mat[i][j] != target[n-j-1][i]) c[3] = false;
            }
        }
        
        return (c[0] or c[1] or c[2] or c[3]);
    }
};