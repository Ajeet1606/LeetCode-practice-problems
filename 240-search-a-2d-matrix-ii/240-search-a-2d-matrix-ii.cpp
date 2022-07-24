class Solution {
public:
    //apply binary search in every row.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<m; i++){
            //as rows and cols are sorted.
            if(matrix[i][0] > target) break;
            //search the target in ith row.
            found = search(matrix[i], 0, n-1, target);
            //if found, don't go in further rows, break;
            if(found) break;
        }
        
        return found;
    }
    
    //search function.
    bool search(vector<int>&arr, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] > target){
                r= mid-1;
            }
            else if(arr[mid] < target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};