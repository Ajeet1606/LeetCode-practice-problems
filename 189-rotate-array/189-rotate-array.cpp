class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // O(n) time and O(n) space
        int n = arr.size();
        if(k>n)
            k = k%n;
        vector<int>a(n); 
        int st = 0;
        for(int i = n-k; i<n; i++){
            a[st] = arr[i];
            st++;
        }
        for(int i=0; i<n-k; i++){
            a[st] = arr[i];
            st++;
        }
        arr = a;
    }
};