class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int dup = -1, missing = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                dup = arr[i];
            }
            else if(arr[i] > arr[i-1]+1){
                missing = arr[i-1]+1;
            }
        }
        
        if(arr[n-1] != n)
            missing = n;
        return {dup, missing};
    }
};