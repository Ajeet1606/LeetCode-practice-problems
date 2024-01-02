class Solution {
public:
    int maxSubArray(vector<int>& arr) {
// optimised.
        int n = arr.size();
        int ans = -1e5;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};