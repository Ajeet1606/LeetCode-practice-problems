class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        if(n < 3) return {};

        sort(arr.begin(), arr.end());
        if(arr[0] > 0) return {};

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }

        for(int i=0; i<n-1; i++){
            if(arr[i] > 0) break;
            for(int j=i+1; j<n; j++){
                int target = (-1)* (arr[i]+arr[j]);
                if(mp.count(target) && mp[target] > j){
                    ans.push_back({arr[i], arr[j], target});
                }
                j = mp.find(arr[j])->second;
            }
            i =mp.find(arr[i])->second;
        }
        return ans;
    }
};