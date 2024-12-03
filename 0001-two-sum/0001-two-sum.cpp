class Solution {
public: //one paas map.
    vector<int> twoSum(vector<int>& arr, int target) {
        int len = arr.size();
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<len; i++){
            int compliment = target - arr[i];
            if(mp.find(compliment) != mp.end()){
                return {i, mp[compliment]};
            }
            mp[arr[i]] = i;
        }
        
        return {};
    }
};