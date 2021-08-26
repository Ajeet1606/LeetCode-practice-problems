class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int r = piles.size()-1, l = 1;
        long int ans = 0;
        while(l<r){
            ans += piles[l];
            r--;
            l += 2;
        }
        return ans;
    }
};