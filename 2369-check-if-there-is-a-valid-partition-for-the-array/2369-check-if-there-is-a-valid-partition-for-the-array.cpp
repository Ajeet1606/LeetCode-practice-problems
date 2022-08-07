class Solution {
public:
    
    bool solve(int i, vector<int>&dp, vector<int>&arr, int &n){
        //if we reach end return true
        if(i == n) return true;
        //already calculated, return
        if(dp[i] != -1) return dp[i];
        
        
        //2 size subarray exist
        if(i+1 < n and arr[i] == arr[i+1]){
            if(solve(i+2, dp, arr, n))  return true;
            //3 size subarray
            if(i+2 < n and arr[i] == arr[i+2])
                if(solve(i+3, dp, arr, n))  return true;
        }
        //3 size subarray
        if(i+2 < n and arr[i] == arr[i+1]-1 and arr[i] == arr[i+2]-2){
            if(solve(i+3, dp, arr, n))
                return true;
        }
        //nothing found, ans false
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& arr) {
        int n = arr.size();
        //store results
        vector<int>dp(n, -1);
        
        return solve(0, dp, arr, n);
       
    }
};