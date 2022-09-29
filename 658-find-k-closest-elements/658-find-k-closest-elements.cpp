class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        vector<int>ans;
        
        while(r - l + 1 > k){
            if(abs(x - arr[l]) <= abs(x - arr[r])){
                r--;
            }else{
                l++;
            }
        }
        
        for(int i=l; i<=r; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};