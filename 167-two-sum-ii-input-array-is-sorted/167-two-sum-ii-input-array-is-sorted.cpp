class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int l=0, r = n-1;
        while(arr[l]+arr[r]!= target){
            if(arr[l]+arr[r] > target)
                r--;
            else
                l++;
        }
        return {l+1, r+1};
    }
};