class Solution {
public:
    bool ans = false;
    
    void fun(int n, vector<vector<int>>&adj, int source, int d, vector<bool>&vis){
        if(vis[source]) return;
        cout<<source<<" ";
        vis[source] = true;
        for(auto a: adj[source]){
            if(a == d){
                ans = true;
                return;
            }
            fun(n, adj, a, d, vis);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int d) {
        if(n == 1){
            return source == d;
        }
        vector<vector<int>>adj(n);
        
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(n, false);
        
        fun(n, adj, source, d, vis);
        return ans;
    }
};