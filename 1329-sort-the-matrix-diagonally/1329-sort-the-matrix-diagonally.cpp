class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        //starting from bottom
        int i=rows-1, j=0;
        while(i>=0){
            int r = i, c = j;
            vector<int>a;
            while(r<rows and c <cols){
                a.push_back(mat[r++][c++]);
            }
            
            sort(a.begin(), a.end());
            r = i, c = j;
            int idx = 0;
            while(r<rows and c <cols){
                mat[r++][c++] = a[idx++];
            }
            
            i--;
        }
        
        //start from left
        i=0; j=0;
        while(j<cols){
            int r = i, c = j;
            vector<int>a;
            while(r<rows and c <cols){
                a.push_back(mat[r++][c++]);
            }
            
            sort(a.begin(), a.end());
            r = i, c = j;
            int idx = 0;
            while(r<rows and c <cols){
                mat[r++][c++] = a[idx++];
            }
            
            j++;
        }
        
        return mat;
    }
};