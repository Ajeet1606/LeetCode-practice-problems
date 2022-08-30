class Solution {
public:
    
    void transpose(vector<vector<int>>&matrix){
        int n = matrix.size();
        for (int i = 0; i < n; ++i){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        
        transpose(matrix);
    }
};