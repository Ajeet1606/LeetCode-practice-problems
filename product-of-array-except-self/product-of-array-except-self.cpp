class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1), prefix(n), suffix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1]*nums[i];
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1]*nums[i];
        for(int i = 0; i<n; i++){
            if(nums[i]==0)
            {
                if(i>0)
                    res[i] *= prefix[i-1];
                if(i<n-1)
                    res[i] *= suffix[i+1];
            }
            else
            res[i] = (prefix[i]/nums[i])*(suffix[i]/nums[i]);
        }
        return res;
    }
};