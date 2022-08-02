class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n-1][n-1];
        while(start < end){
            int mid = start + (end - start)/2;
            int nums = numsSmallerThanMid(matrix, mid);
            
            if(nums < k){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
    
    int numsSmallerThanMid(vector<vector<int>>& matrix, int mid){
        int n = matrix.size(), row = n-1, col = 0, ans = 0;
        while(row >= 0 and col < n){
            if(matrix[row][col] > mid){
                row--;
            }
            else{
                ans += row+1;
                col++;
            }
        }
        return ans;
    }
};