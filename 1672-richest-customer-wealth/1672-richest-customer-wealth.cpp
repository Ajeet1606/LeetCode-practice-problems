class Solution {
public:
    int maximumWealth(vector<vector<int>>& arr) {
        int m = arr.size();
        int ans = 0;
        for(int i=0; i<m; i++){
            int sum  = 0;
            for(int j=0; j<arr[i].size(); j++){
                sum += arr[i][j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};