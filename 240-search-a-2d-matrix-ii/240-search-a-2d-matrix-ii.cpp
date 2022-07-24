class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0;
        while(i<m and n>0){
            if(matrix[i][n-1] == target){
                return true;
            }
            else{
                matrix[i][n-1]> target? n--: i++;
            }
        }
        
        return false;;
    }
    
    
};