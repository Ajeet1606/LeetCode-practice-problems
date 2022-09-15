class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n&1) return {};
        unordered_map<int, int>mp, used;
        for(auto &c: changed)
            mp[c]++;
        
        sort(changed.begin(), changed.end());
        vector<int>ans;
        bool flag = true;
        for(int i=0; i<n and flag; i++){
            if(used[changed[i]] > 0){
                used[changed[i]]--;
                continue;
            }
            int twice = 2*changed[i];
            if(mp[twice] > 0){
                ans.push_back(changed[i]);
                mp[twice]--;
                used[twice]++;
            }else{
                flag = false;
            }
        }
        if(flag) return ans;
        return {};
    }
};