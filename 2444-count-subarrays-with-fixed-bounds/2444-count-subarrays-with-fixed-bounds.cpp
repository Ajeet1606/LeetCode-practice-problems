class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mnPos = -1, mxPos = -1, left = -1;
        
        for(int i=0; i< nums.size(); i++){
            if(nums[i] == minK) mnPos = i;
            if(nums[i] == maxK) mxPos = i;
            if(nums[i] < minK or nums[i] > maxK) left = i;
            
            ans += max(0, min(mnPos, mxPos) - left);
        }
        
        return ans;
    }
};