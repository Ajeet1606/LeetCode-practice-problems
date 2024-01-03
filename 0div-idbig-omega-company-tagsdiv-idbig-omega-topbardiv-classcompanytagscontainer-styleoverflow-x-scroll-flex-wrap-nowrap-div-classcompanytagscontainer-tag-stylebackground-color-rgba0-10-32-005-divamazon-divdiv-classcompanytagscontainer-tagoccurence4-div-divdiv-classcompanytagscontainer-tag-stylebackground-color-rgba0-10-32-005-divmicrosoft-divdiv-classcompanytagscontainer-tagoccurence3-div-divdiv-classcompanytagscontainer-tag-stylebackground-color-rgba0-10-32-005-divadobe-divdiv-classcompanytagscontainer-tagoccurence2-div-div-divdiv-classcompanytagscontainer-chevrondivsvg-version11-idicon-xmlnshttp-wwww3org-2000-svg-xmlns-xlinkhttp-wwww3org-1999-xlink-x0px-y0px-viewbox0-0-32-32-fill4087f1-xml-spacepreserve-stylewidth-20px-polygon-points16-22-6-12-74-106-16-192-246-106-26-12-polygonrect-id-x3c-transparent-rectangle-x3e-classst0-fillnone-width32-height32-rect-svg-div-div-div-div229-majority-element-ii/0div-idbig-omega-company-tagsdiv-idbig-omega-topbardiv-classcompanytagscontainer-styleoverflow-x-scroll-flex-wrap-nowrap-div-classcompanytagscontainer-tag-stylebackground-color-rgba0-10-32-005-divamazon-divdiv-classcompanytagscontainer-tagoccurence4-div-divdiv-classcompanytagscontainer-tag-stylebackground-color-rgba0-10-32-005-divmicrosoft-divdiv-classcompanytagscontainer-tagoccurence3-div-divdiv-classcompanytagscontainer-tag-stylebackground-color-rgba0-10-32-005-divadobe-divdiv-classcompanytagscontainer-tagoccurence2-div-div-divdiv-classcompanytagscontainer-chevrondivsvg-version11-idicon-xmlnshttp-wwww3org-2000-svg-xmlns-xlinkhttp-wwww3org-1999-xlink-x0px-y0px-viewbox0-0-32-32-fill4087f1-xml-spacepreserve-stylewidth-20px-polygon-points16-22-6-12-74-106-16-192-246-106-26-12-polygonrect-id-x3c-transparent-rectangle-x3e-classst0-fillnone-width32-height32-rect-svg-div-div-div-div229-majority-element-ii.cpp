class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        //1. use frequency map
        //2. sort
        int n = arr.size();
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<int>ans;
        for(auto [key, value]: mp){
            if(value > n/3)
                ans.push_back(key);
        }
        return ans;
    }
};