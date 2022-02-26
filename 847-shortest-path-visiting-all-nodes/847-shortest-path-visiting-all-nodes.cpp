class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> W(n , vector<int>(n , 150));
        //150 is a random large number depending on the given input constraints
        for(int i = 0 ; i < n ; i++) //distance to self is zero
            W[i][i] = 0;
        
        for(int i = 0 ; i < n ; i++){ // distance to neighbor is 1 , else infi
            for(int j : graph[i]){
                W[i][j] = 1;
            }
        }
        
        
        for(int i = 0 ; i < n ; i++){ // nearest dist b/w each pair of nodes
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    W[i][j] = min(W[i][j] , W[i][k] + W[k][j]); // basically implementing the floyd warshall algo
                }
            }
        }
        
        vector<vector<int>> dp(1<<n , vector<int>(n, 150));
        
        for(int i = 0 ; i < n ; i++){
            dp[1<<i][i] = 0; // total distance after visiting one node from the same node is 0
        }
        
        for(int mask = 0 ; mask < 1<< n ; mask++){
            
            vector<int> nz;
            for(int j = 0 ; j < n; j++){
                if(mask & (1 << j))
                    nz.push_back(j); // finding pos of non-zero bits, i.e. nodes visited
            }
            
            for(int j : nz){ // j is the last node visited by mask
                for(int k : nz){//k is the node last visited by the neighbor mask
                    if(j != k){
                    int neib = dp[mask ^ (1 << j)][k]; // neighbor mask has not yet visited jth node, and it is ending up at kth node
                    dp[mask][j] = min(dp[mask][j] , neib + W[k][j]);
					//neib + W[k][j] means neighbor mask ends at kth node, and then visits jth node from k to become the current mask
                    }
                }
            }
            
        }
        
        int res = 150;
        
        for(int i = 0 ; i < n ; i++)
            res = min(res, dp.back()[i]); // finding min dist after visiting all nodes and ending at ith node
            
        return res;
    }
};