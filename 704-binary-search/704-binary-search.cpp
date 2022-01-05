class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n-1;
        if(arr[l] > target or arr[r] < target)
            return -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid]> target){
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return -1;
    }
};