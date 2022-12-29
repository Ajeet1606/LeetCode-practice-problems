class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        
        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    isWater[i][j] = 0;
                    q.push({i, j});
                }else{
                    isWater[i][j] = -1;
                }
            }
        }
        vector<int>dx = {0, 1, 0, -1, 0};
        int h = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                for(int i=0; i<4; i++){
                    int xx = x+dx[i];
                    int yy = y+dx[i+1];
                    if(xx>=0 and xx<m and yy>=0 and yy<n and isWater[xx][yy] == -1){
                        isWater[xx][yy] = h+1;
                        q.push({xx, yy});
                    }
                }
                q.pop();
            }
            h++;
        }
        
        return isWater;
    }
};