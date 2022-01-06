class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        int a = n-1;
        int l = 0, r = n-1;
        while(l<=r){
            if(abs(arr[r]) > abs(arr[l])){
                ans[a] = arr[r]*arr[r];
                r--;
            }
            else{
                ans[a] = arr[l]*arr[l];
                l++;
            }
            a--;
        }
        return ans;
    }
};