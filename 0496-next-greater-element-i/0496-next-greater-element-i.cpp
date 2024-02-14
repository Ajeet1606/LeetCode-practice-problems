class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int>ans;
        for(int i=0; i<n1; i++){
            int cur = arr1[i], idx;
            for(int j=0; j<n2; j++){
                if(arr2[j] == arr1[i]){
                    idx = j;
                    break;
                }
            }
            bool found = false;
            for(int j=idx; j<n2; j++){
                if(arr2[j] > arr1[i]){
                    ans.push_back(arr2[j]);
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};