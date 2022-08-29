class Solution {
public:
        //BFS
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int arr[5] = {0, 1, 0, -1, 0};
        
        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    ans++;
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int>p = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int r = p.first + arr[k];
                            int c = p.second + arr[k+1];
                            if(r<0 or r>=rows or c<0 or c>=cols or grid[r][c] != '1') continue;
                            q.push({r, c});
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};