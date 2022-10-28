class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string>sorted_strings(n);
        
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            sorted_strings[i] = s;
        }
        
        unordered_map<string, vector<string>>m;
        
        for(int i=0; i<n; i++){
            m[sorted_strings[i]].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;
        for(auto [key, value]: m){
            vector<string>v;
            for(auto str: value){
                v.push_back(str);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};