//Recusrion

class Solution {
public:
    vector<int>dp;
    int fun(int idx, vector<int>&arr){
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int pick = arr[idx] + fun(idx-2, arr);
        int skip = fun(idx-1, arr);
        
        return dp[idx] = max(pick, skip);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, -1);
        return fun(n-1, arr);
    }
};