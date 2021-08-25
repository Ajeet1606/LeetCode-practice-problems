class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& index) {
        vector<vector<int>>mat(m, vector<int>(n, 0));
        for(int i = 0; i < index.size(); i++){
            int row = index[i][0], col = index[i][1];
            for(int j = 0; j < n; j++)
                mat[row][j]++;
            for(int j = 0; j < m; j++)
                mat[j][col]++;
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]&1)
                    res++;
            }
        }
        return res;
    }
};