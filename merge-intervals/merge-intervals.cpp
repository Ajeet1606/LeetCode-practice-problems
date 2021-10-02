class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>>ans;
        vector<int>t{a[0][0], a[0][1]};
        ans.push_back(t);
        int j = 0;
        for(int i = 1; i < a.size(); i++){
            if(ans[j][1]>=a[i][0])
            {
                ans[j][0] = min(ans[j][0], a[i][0]);
                ans[j][1] = max(ans[j][1], a[i][1]);                }
            else{
                vector<int>t;
                t.push_back(a[i][0]);
                t.push_back(a[i][1]);
                ans.push_back(t);
                j++;
            }
        }
        return ans;
    }
};