class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // O(n) time and O(1) space
        int n = arr.size();
        if(k==0 or k==n) return;
        k %=n;
        reverse(arr.begin(), arr.begin()+n-k);
        reverse(arr.begin()+n-k, arr.end());
        reverse(arr.begin(), arr.end());
    }
};