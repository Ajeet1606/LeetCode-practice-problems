class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int>arr(n*n);
        int idx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[idx++] = matrix[i][j];
            }
        }
        
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};