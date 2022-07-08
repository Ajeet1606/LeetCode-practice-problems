class Solution {
public:
    int memo[100][100][21];
    const int MAX_COST = 1000001;
    
    int findMinCost(vector<int>&houses, vector<vector<int>>& cost, int target, int currIdx, int nebCnt, int prevClr){
        if(currIdx == houses.size()){
            return nebCnt == target ? 0: MAX_COST;
        }
        
        if(nebCnt > target){
            return MAX_COST;
        }
        
        if(memo[currIdx][nebCnt][prevClr] != -1){
            return memo[currIdx][nebCnt][prevClr];
        }
        
        int minCost = MAX_COST;
        if(houses[currIdx]){
            int newNebCnt = nebCnt + (houses[currIdx] != prevClr);
            minCost = findMinCost(houses, cost, target, currIdx+1, newNebCnt, houses[currIdx]);
        }
        else{
            int totalClrs = cost[0].size();
            
            for(int clr=1; clr <= totalClrs; clr++){
                int newNebCnt = nebCnt + (clr != prevClr);
                int currCost = cost[currIdx][clr-1] + findMinCost(houses, cost, target, currIdx+1, newNebCnt, clr);
                minCost = min(minCost, currCost);
            }
        }
        
        return memo[currIdx][nebCnt][prevClr] = minCost;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(memo, -1, sizeof(memo));
        int ans = findMinCost(houses, cost, target, 0, 0, 0);
        return ans == MAX_COST? -1: ans;
        
    }
};