class Solution {
public:
    
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, int &ans){
        //here we come with non-restricted nodes only
        //mark them as visited
        visited[node] = true;
        //update ans
        ans++;
        //go to it's connected nodes.
        for(auto a: graph[node]){
            if(visited[a] == false){
                dfs(a, graph, visited, ans);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //make adjacency list
        vector<vector<int>>graph(n);
        //array to store restricted nodes
        vector<bool>visited(n);
        for(auto a: restricted){
            visited[a] = true;
        }
        //create list
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int ans = 0;
        dfs(0, graph, visited ,ans);
        return ans;
    }
};