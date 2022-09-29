class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans;
        
        unordered_map<int, vector<int>>map;
        int mn_diff = INT_MAX, mx_diff = INT_MIN;
        
        for(int i=0; i<n; i++){
            int diff = abs(x - arr[i]);
            map[diff].push_back(arr[i]);
            mn_diff = min(mn_diff, diff);
            mx_diff = max(mx_diff, diff);
        }
        //cout<<mn_diff<<' '<<mx_diff;
        int nums_taken = 0;
        for(int i= mn_diff; i<= mx_diff; i++){
            for(auto a: map[i]){
                ans.push_back(a);
                nums_taken++;
                if(nums_taken == k) break;
            }
            if(nums_taken == k) break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};