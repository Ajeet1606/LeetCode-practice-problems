class Solution {
public:
    int minMoves2(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int i=0, j=n-1;
        int ans = 0;
        while(i<j){
            ans += arr[j] - arr[i];
            i++; 
            j--;
        }
        return ans;
    }
};