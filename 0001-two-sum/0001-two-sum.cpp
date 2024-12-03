class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int len = arr.size();
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<len; i++){
            mp[arr[i]] = i;
        }
        
        for(int i=0; i<len; i++){
            int cur = arr[i];
            int rem = target - cur;
            if(mp.find(rem) != mp.end() && mp[rem] > i){
                return {i, mp[rem]};
            }
        }
        return {};
    }
};