class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        unordered_set<int>row, col;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        //traverse row 
        for(auto &r: row){
            for(int j=0; j<n; j++){
                arr[r][j] = 0;
            }
        }
        
        //col
        for(auto &c: col){
            for(int j=0; j<m; j++){
                arr[j][c] = 0;
            }
        }
    }
};