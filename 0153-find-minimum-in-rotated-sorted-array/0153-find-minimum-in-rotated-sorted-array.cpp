class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            ans = min(ans, arr[m]);
            
            if(arr[m] > arr[r]){
                l = m+1;    
            }else{
                r= m-1;
            }
        }
        return ans;
    }
};