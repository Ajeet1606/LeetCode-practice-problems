class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        int dup = -1, missing = 1;
        
        for(auto a: arr){
            if(arr[abs(a) - 1] < 0)
                dup = abs(a);
            else
                arr[abs(a) - 1] *= -1;
        }
        
        for(int i=1; i<n; i++){
            if(arr[i] > 0){
                missing = i+1;
            }
        }
        
        return {dup, missing};
    }
};