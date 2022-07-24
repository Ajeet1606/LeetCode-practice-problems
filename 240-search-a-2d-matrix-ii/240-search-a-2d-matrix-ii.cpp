class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<m and n>0; i++){
            //last column
            if(matrix[i][n-1] < target){
                continue;
            }
            else if(matrix[i][n-1] > target){
                n--;
                i--;
            }
            else{
                return true;
            }
        }
        
        return false;;
    }
    
    
};