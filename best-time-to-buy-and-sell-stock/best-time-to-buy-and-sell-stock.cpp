class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(), minPrice = INT_MAX, maxProfit = 0;
        for(int i = 0; i < n; i++){
            if(p[i]<minPrice)
                minPrice = p[i];
            else if(p[i] - minPrice > maxProfit)
                maxProfit = p[i] - minPrice;
        }
        return maxProfit;
    }
};