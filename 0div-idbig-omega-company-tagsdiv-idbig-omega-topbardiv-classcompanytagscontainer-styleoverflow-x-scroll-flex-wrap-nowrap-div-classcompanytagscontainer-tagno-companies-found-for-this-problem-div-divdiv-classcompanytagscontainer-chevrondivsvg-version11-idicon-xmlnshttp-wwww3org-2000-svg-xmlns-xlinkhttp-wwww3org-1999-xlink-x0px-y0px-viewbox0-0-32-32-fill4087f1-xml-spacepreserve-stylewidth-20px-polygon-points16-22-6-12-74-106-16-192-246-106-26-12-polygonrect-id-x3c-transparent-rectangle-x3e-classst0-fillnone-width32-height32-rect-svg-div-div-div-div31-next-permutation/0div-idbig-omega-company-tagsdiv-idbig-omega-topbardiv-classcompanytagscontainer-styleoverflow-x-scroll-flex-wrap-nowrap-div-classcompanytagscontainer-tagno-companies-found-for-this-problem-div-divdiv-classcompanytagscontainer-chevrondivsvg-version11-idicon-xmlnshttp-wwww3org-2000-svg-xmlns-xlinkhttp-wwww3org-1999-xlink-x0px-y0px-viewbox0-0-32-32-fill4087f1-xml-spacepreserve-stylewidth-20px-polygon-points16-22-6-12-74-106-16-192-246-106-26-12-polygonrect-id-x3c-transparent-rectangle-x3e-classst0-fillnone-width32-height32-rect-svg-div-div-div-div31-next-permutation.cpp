class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return;
        
        int x = -1;
        
        for(int idx = n-1; idx > 0; --idx){
            if(arr[idx-1] < arr[idx]){
                x = idx-1;
                break;
            }
        }
        if(x == -1){
            sort(arr.begin(), arr.end());
            return;
        }
        int val = arr[x];
        sort(arr.begin()+x, arr.end());
        int nextGreaterValIdx = 0;
        
        for(int idx=x; idx<n; idx++){
            if(arr[idx] > val){
                nextGreaterValIdx = idx;
                break;
            }
        }
        
        swap(arr[x], arr[nextGreaterValIdx]);
        sort(arr.begin()+x+1, arr.end());
    }
};