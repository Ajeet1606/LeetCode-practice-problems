class Solution {
public:
    vector<int> maxSubsequence(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>temp(n, INT_MIN);
        for(int i=0; i<k; i++){
            int mx = INT_MIN, id;
            for(int j=0; j<n; j++){
                if(mx < arr[j] and arr[j] != INT_MAX){
                    mx = arr[j];
                    id = j;
                }
            }
            arr[id] = INT_MAX;
            temp[id] = mx;
        }
        
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(temp[i] != INT_MIN)
                ans.push_back(temp[i]);
        }
        
        return ans;
    }
};