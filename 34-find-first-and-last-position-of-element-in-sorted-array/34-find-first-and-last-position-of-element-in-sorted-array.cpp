class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target){
        int n = arr.size();
        int l=0, r=n-1, idx=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] == target){
                idx = mid;
                break;
            }
            else{
                arr[mid]>target? r=mid-1: l=mid+1;
            }
        }
        if(idx == -1){
            return {-1, -1};
        }
        int st, end, temp = idx;
        while(temp>=0 and arr[temp] == target)
            temp--;
        st = temp+1;
        temp = idx;
        while(temp<n and arr[temp] == target)
            temp++;
        end = temp-1;
        return {st, end};
    }
};