class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        //starting from bottom
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>pq;
        //map<int, priority_queue<int, vector<int>, greater<int>>>pq;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                pq[i-j].push(mat[i][j]);
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                mat[i][j] = pq[i-j].top();
                pq[i-j].pop();
            }
        }
        return mat;
    }
};