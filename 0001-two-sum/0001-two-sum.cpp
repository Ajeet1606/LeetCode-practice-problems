class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int len = arr.size();
        
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(arr[i] + arr[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};