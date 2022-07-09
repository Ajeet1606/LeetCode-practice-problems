class Solution {
public:
    //optimized dp
    int maxResult(vector<int>& arr, int k) {
        //make dp array.
        vector<int>dp(size(arr), INT_MIN);
        //initialise dp[0] = arr[0] and insert into multiset s. 
        multiset<int>s({dp[0] = arr[0]});
        // traverse arr.
        for(int i=1; i<size(arr); i++){
            // we need previous k nums for ith idx, so when i>k, erase i-k-1.
            if(i>k){
                s.erase(s.find(dp[i-k-1]));
            }
            //pick the largest previous number and assign dp[i]
            dp[i] = *rbegin(s)+arr[i];
            //insert to s.
            s.insert(dp[i]);
        }
        //last value of dp is ans.
        return dp.back();
    }
};