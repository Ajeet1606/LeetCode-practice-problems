class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // O(n) time and O(k) space
        int n = arr.size();
        if(k>n)
            k %=n;
        vector<int>a(n-k);
        for(int i = 0; i<n-k; i++){
            a[i] = arr[i];
        }
        int l = 0, r = n-k;
        while(r < n){
            swap(arr[l++], arr[r++]);
        }
        int st = 0;
        for(int i = k; i<n; i++){
            arr[i] = a[st++];
        }
    }
};