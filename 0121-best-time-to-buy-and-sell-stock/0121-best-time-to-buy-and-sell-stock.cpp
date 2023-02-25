class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prefix(n, 0);
        int mx= 0;
        for(int i = n-1; i>=0; --i){
            mx = max(mx, prices[i]);
            prefix[i] = mx;
        }
        
        int ans = 0;
        for(int i=0; i<n-1; i++){
            ans = max(ans, prefix[i+1] - prices[i]);
        }
        
        return ans;
    }
};