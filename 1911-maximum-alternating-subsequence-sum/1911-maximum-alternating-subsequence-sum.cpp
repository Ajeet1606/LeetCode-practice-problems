class Solution {
public:
    
    long long dp[2][100001];
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return fun(arr, n, 0, 0);
    }
    
    long long fun(vector<int>&arr, int n, int cur, int pos){
        if(cur >= n) return 0;
        
        if(dp[pos][cur] != -1) return dp[pos][cur];
        //pick cur
        //if pos is (true)even add in sum
        //else subtract from sum.
                
        long long pick, skip;
        if(pos == 0)
            pick = fun(arr, n, cur+1, 1) + arr[cur];
        else
            pick = fun(arr, n, cur+1, 0) - arr[cur];
        
        //skip cur
        
        skip = fun(arr, n, cur+1, pos);
        
        return dp[pos][cur] = max(pick, skip);
    }
};