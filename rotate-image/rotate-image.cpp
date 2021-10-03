class Solution {
public:
    
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void reverse(vector<vector<int>>& matrix){
        int j = 0, k = matrix.size()-1, i = 0;
        while(j < k){
            swap(matrix[i][j], matrix[i][k]);
            if(i == matrix.size()-1){
                i = 0; j++; k--;
            }
            else
                i++;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};