class Solution {
public:
    int rows, cols;
    
    void waterFlowFromAtlantic(vector<vector<int>>&matrix,
    vector<vector<bool>>&atlantic, int prev, int i, int j) {

    if (i < 0 or i >= rows or j >= cols or j < 0 or matrix[i][j] < prev or 
        atlantic[i][j]){
        return;
    }
    atlantic[i][j] = true;
    
    waterFlowFromAtlantic(matrix, atlantic, matrix[i][j], i, j+1);
    waterFlowFromAtlantic(matrix, atlantic, matrix[i][j], i+1, j);
    waterFlowFromAtlantic(matrix, atlantic, matrix[i][j], i, j-1);
    waterFlowFromAtlantic(matrix, atlantic, matrix[i][j], i-1, j);
    
}


void waterFlowFromPacific(vector<vector<int>>&matrix,
    vector<vector<bool>>&pacific, int prev, int i, int j) {

    if (i < 0 or i >= rows or j >= cols or j < 0 or matrix[i][j] < prev or 
        pacific[i][j]){
        return;
    }
    pacific[i][j] = true;
    
    waterFlowFromPacific(matrix, pacific, matrix[i][j], i, j+1);
    waterFlowFromPacific(matrix, pacific, matrix[i][j], i+1, j);
    waterFlowFromPacific(matrix, pacific, matrix[i][j], i, j-1);
    waterFlowFromPacific(matrix, pacific, matrix[i][j], i-1, j);
}
    
    ///main function
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
    vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));
    vector<vector<bool>>pacific(rows, vector<bool>(cols, false));

    //taking water from pacific 
    //left side
    for (int i = 0; i < rows; ++i){
        waterFlowFromPacific(matrix, pacific, -1, i, 0);
    }
    
    //top side
    for (int i = 0; i < cols; ++i){
        waterFlowFromPacific(matrix, pacific, -1, 0, i);
    }

    //atlantic
    //right side
    for (int i = 0; i < rows; ++i){
        waterFlowFromAtlantic(matrix, atlantic, -1, i, cols-1);
    }
    
    //bottom
    for (int i = 0; i < cols; ++i){
        waterFlowFromAtlantic(matrix, atlantic, -1, rows-1, i);
    }
    

    vector<vector<int>>ans;
    for (int i = 0; i < rows; ++i){
        for(int j=0; j<cols; j++){
            if (atlantic[i][j] and pacific[i][j]){
                ans.push_back({i, j});
            }
        }
    }
        return ans;
    }
};