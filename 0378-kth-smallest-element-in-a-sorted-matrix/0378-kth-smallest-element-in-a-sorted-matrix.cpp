class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = rows;
        int pqSize = 0;
        priority_queue<int>pq;
        
        for(int rowIdx = 0; rowIdx < rows; rowIdx++){
            for(int colIdx = 0; colIdx < cols; colIdx++){
                pq.push(matrix[rowIdx][colIdx]);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};