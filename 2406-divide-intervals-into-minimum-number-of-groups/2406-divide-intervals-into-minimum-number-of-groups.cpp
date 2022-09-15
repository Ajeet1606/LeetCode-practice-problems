class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = 1000011;
        vector<int>a(n, 0);
        for(auto x: intervals){
            a[x[0]]++;
            a[x[1]+1]--;
        }
        
        //prefix sum
        for(int i=1; i<n-1; i++){
            a[i] += a[i-1];
        }
        
        int ans = 0;
        for(auto i: a)
            ans = max(ans, i);
        return ans;
    }
};