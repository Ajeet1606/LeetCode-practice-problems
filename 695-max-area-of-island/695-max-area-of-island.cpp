class Solution {
public:
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    cout<<i<<" "<<j<<endl;
                    int cnt = fun(grid, i, j);
                    ans = max(ans, cnt);
                    //cout<<cnt<<endl;
                }
            }
        }
        return ans;
    }
    
    
    int fun(vector<vector<int>>& grid, int i, int j){
        if(i<0 or i>=m or j<0 or j>=n) return 0;
        int cnt = 0;
        if(grid[i][j] == 1){
            cnt++;
            grid[i][j] = 0;
            //check top
            cnt += fun(grid, i-1, j);
            //check bottom
            cnt += fun(grid, i+1, j);
            //check left
            cnt += fun(grid, i, j-1);
            //check right
            cnt += fun(grid, i, j+1);
        }
        return cnt;
    }
};