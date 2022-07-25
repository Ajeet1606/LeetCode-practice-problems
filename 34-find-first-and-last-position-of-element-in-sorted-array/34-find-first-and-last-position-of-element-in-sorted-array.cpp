class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        int st = search(nums, target, 0, n-1, true);
        int end = search(nums, target, 0, n-1, false);
        return {st, end};
    }
    
    int search(vector<int>&nums, int target, int l, int r, bool forLeft){
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                ans = mid;
                //we'll search more on left/right;
                if(forLeft){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};