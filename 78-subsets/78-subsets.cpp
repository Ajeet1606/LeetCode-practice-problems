class Solution {
public:
    vector<vector<int>>ans;
    void generate(vector<int>&subset, int i, vector<int>&nums){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
        
        // not picking ith element
        generate(subset, i+1, nums);
        
        // pick ith element
        subset.push_back(nums[i]);
        generate(subset, i+1, nums);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>empty;
        generate(empty, 0, nums);
        return ans;
    }
};