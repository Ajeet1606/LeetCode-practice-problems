class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        vector<int>ans(len);
        for(int i = 0; i < len; i++){
            int j;
            for(j = i+1; j < len; j++){
                if(prices[i]>=prices[j]){
                    ans[i] = prices[i] - prices[j];
                    break;
                }
            }
            if(j==len) ans[i] = prices[i];
        }
        return ans;
    }
};