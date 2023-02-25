class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least_so_far = INT_MAX;
        int profit_if_sold_today = 0;
        int current_profit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            least_so_far = min(least_so_far, prices[i]);
            
            profit_if_sold_today = prices[i] - least_so_far;
            
            current_profit = max(current_profit, profit_if_sold_today);
        }
        
        return current_profit;
    }
};