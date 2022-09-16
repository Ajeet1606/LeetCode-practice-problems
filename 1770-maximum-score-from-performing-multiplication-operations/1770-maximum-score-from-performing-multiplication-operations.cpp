class Solution {
public:
    //vector<vector<int>>dp;
    int dp[1001][1001];
    int findScore(int idx, vector<int>& nums, vector<int>& M, int left){          //base condition
        if(idx == M.size()) return 0;
        
        if(dp[idx][left] != INT_MIN) 
            return dp[idx][left];
        
        int right = nums.size() - (idx - left) - 1;
        //pick left
        int score1 = M[idx]*nums[left] + findScore(idx+1, nums, M, left+1);
        
        //pick right
        int score2 = M[idx]*nums[right] + findScore(idx+1, nums, M, left);
        
        return dp[idx][left] = max(score1, score2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
                
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return findScore(0, nums, multipliers, 0);
    }
};