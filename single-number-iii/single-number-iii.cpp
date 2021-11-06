class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 2) return nums;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-1; i++){
            if(nums[i]!=nums[i+1])
                ans.push_back(nums[i]);
            else
                i++;
            if(ans.size()==2) break;
        }
        if(ans.size()<2)
            ans.push_back(nums[len-1]);
        return ans;
    }
};