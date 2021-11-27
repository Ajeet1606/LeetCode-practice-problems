class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int>res(n,1);
        int left = 1;
        for(int i = 0; i<n; i++){
            if(i>0)
                left = left*arr[i-1];
            res[i] *= left;
        }
        int right = 1;
        for(int i = n-1; i>= 0; i--){
            if(i<n-1)
                right = right*arr[i+1];
            res[i] *= right;
        }
        return res;
    }
};