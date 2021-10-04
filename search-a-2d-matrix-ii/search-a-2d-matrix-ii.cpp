class Solution {
public:
    
    bool search(vector<vector<int>>& matrix, int target, int row){
        int l = 0, r = matrix[row].size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int m= matrix[i][0];
            int n = matrix[i][matrix[i].size() - 1];
            if(m == target || n == target)
                return true;
            if(m < target && n > target){
                if(search(matrix, target, i))
                    return true;
            }
        }
        return false;
    }
};