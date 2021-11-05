class Solution {
public:
    
    
    int arrangeCoins(int n) {
        int ans = 0;
        int i=1;
        while(1){
            if(i<=n){
                n -= i;
                ans++;
                i++;
            }
            else
                break;
        }
        return ans;
    }
};