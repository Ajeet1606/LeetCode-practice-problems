class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>arr(n+1, 0);
        
        int mx = 0;
        for(int i=1; i<=n; i++){
            arr[i] = arr[i-1] + gain[i-1];
            mx = max(mx, arr[i]);
        }
        
        return mx;
    }
};