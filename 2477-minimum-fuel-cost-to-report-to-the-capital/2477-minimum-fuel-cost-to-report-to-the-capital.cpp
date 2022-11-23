class Solution {
public:
    
    long long ans = 0;
    
    long long dfs(vector<vector<int>>&v, int node, vector<bool>&vis, int seats){
        //mark visited
        vis[node] = true;
        
        long long cnt = 1;
        //traverse connected nodes
        for(auto cur: v[node]){
            //if not visited 
            if(!vis[cur]){
                // go for that.
                cnt += dfs(v, cur, vis, seats);
            }
        }
        //find number of cars needed.
        long long x = cnt/seats;
        if(cnt % seats) x++;
        //if we don't reach 0, we x cost to carry x cars.
        if(node != 0) ans += x;
        return cnt;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        if(n == 0) return 0;
        
        //create adjacency list
        vector<vector<int>>tree(n+1);
        for(auto road: roads){
            tree[road[0]].push_back(road[1]);
            tree[road[1]].push_back(road[0]);
        }
        
        //create visited array
        vector<bool>vis(n+1, 0);
        dfs(tree, 0, vis, seats);
        
        return ans;
    }
};