class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>>arr(n, vector<int>(n, 0));
        
        int l1 = q.size();
        for(int i=0; i< l1; i++){
            int r1 = q[i][0], c1 = q[i][1], r2 = q[i][2], c2 = q[i][3];
            
            //line sweep algorithm, apply on 1D first.
            for(int row = r1; row <= r2; row++){
                arr[row][c1]++;
                if(c2 < n-1) arr[row][c2+1]--;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                arr[i][j] += arr[i][j-1];
            }
        }
        
        return arr;
    }
};