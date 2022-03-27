class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>>a;
        int idx=0;
        for(auto i: mat){
            int cnt = 0;
            for(auto j: i){
                if(j == 1) cnt++;
            }
            a.push_back({cnt, idx});
            idx++;
        }
        sort(begin(a), end(a));
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(a[i].second);
        }
        return ans;
    }
};