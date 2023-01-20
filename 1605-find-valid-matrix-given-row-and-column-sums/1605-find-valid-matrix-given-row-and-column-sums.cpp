class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>>matrix(n, vector<int>(m, 0));
                
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int mn = min(rowSum[i], colSum[j]);
                matrix[i][j] = mn;
                rowSum[i] -= mn;
                colSum[j] -= mn;
            }
        }
        
        return matrix;
    }
};