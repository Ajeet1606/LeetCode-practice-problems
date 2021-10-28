class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int n = arr.size();
        int ans = -1, mn = INT_MAX;
        for(int i = 0; i < n; i++){
            mn = min(mn, arr[i]);
            if(arr[i]>mn) ans = max(ans, arr[i]-mn);
        }
        return ans;
    }
};