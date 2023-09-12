class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = rows;
        int low = matrix[0][0], high = matrix[rows-1][cols-1];
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int countofSmallNumbers = getCount(matrix, mid);
            if(countofSmallNumbers >= k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
    int getCount(vector<vector<int>>&matrix, int mid){
        int rows = matrix.size();
        int ans = 0;
        
        int row = rows-1, col = 0;
        while(row >=0 and col < rows){
            if(matrix[row][col] > mid){
                row--;
            }else{
                col++;
                ans += row+1;
            }
        }
        
        return ans;
    }
};