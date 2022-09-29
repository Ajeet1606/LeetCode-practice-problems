class Solution {
public:
    //Binary Search + 2 pointer
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //0 to k size
        int n = arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;
        
        while(k--){
            if(r >= n or l>=0 and abs(x-arr[l] <= abs(x-arr[r])))
                l--;
            else
                r++;
        }
        
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
};