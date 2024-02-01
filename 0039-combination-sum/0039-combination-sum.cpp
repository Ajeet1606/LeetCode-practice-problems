class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0, target, arr, candi, ans);
        return ans;
    }
    
    void solve(int idx, int target, vector<int>&arr, vector<int>&candi, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(idx == candi.size()) return;
        if(candi[idx] <= target){
            arr.push_back(candi[idx]);
            solve(idx, target-candi[idx], arr, candi, ans);
            arr.pop_back();
        }
        solve(idx+1, target, arr, candi, ans);
    }
};