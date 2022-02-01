class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mn = arr[0], mx = arr[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            if(arr[i] < mn){
                mn = arr[i];
                mx = mn;
            }
            else if(arr[i]>mx){
                mx = arr[i];
            }
            ans = max(ans, mx-mn);
        }
        return ans;
    }
};