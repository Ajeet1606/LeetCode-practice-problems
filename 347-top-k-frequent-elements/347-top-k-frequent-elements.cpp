class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int, int>>p;
        unordered_map<int, int>m;
        for(auto a: arr){
            m[a]++;
        }
        for(auto a: m){
            p.push_back({a.second, a.first});
        }
        
        sort(begin(p), end(p), greater<pair<int, int>>());
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(p[i].second);
        }
        return ans;
    }
};