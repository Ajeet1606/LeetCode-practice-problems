class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target){
        int n = nums.size();
        if(n==0) return {-1, -1};
        return search(nums, target, 0, n-1);
    }
    
    vector<int>search(vector<int>&nums, int target, int low, int high){
        if(nums[low] == target and nums[high] == target){
            return {low, high};
        }
        if(nums[low] <= target and target <= nums[high]){
            int mid = low + (high - low)/2;
            vector<int>left = search(nums, target, low, mid);
            vector<int>right = search(nums, target, mid+1, high);
            if(left[0] == -1) return right;
            if(right[0] == -1) return left;
            return {left[0], right[1]};
        }
        return {-1,-1};
    }
};