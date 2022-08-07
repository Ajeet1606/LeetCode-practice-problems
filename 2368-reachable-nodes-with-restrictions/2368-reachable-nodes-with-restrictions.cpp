class Solution {
public:
    
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
        
        queue<int>q;
        //we start from 0
        q.push(0);
        while(!q.empty()){
            //pick the front node
            int node = q.front();
            //pop it
            q.pop();
            //update ans
            ans++;
            //mark visited
            visited[node] = true;
            //traverse it's connected nodes
            for(auto a: graph[node]){
                if(!visited[a]){
                    q.push(a);
                }
            }
        }
        return ans;
    }
};