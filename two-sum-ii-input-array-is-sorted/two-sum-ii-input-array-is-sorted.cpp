class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int x) {
        
        int l = 0, r = arr.size()-1;
        while(arr[l] + arr[r] != x){
            if(arr[l] + arr[r] < x)
                l++;
            else
                r--;
        }
        return vector<int>({l+1, r+1});
    }
};