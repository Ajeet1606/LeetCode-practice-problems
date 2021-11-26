class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int len = arr.size();
        int low = 0, high = len-1;
        int resIdx;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target){
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return low;
    }
};