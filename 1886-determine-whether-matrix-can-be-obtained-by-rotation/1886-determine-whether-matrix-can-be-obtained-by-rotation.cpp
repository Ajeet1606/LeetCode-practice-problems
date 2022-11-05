class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        
//         90deg -> transpose + row reverse on matrix
//         180deg -> transpose + row reverse on 90deg rotated matrix
//         270deg -> transpose + row reverse on 180deg rotated mat
        
        if(mat == target) return true;
        
        int deg = 3;
        while(deg--){
            //transpose
            
            for(int i=0; i<m; i++){
                for(int j=i; j<m; j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            
            //row reverse
            for(int i=0; i<m; ++i){
                reverse(mat[i].begin(), mat[i].end());
            }
            
            if(mat == target) return true;
        }
        
        return false;
    }
};