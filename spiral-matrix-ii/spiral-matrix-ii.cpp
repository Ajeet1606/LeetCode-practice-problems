class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n));
        int minr = 0, minc = 0;
        int maxr = n-1, maxc = n-1;
        int cnt = 1;
        while(cnt <= n*n){
            // top wall
            for(int i = minr, j= minc; j<=maxc && cnt <= n*n; j++){
                res[i][j] = cnt++;
            }
            minr++;
            // right wall
            for(int i = minr, j = maxc; i<=maxr && cnt <= n*n; i++){
                res[i][j] = cnt++;
            }
            maxc--;
            // bottom wall
            for(int i = maxr, j = maxc; j >= minc && cnt <= n*n; j--){
                res[i][j] = cnt++;
            }
            maxr--;
            // left wall
            for(int i = maxr, j = minc; i >= minr && cnt <= n*n; i--){
                res[i][j] = cnt++;
            }
            minc++;
        }
        return res;
    }
};