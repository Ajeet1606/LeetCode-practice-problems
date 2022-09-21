class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int>ans(q);
        long sum = 0;
        for(auto a: arr){
            if(!(a&1)){
                sum += a;
            }
        }
        
        //apply queries
        for(int i=0; i<q; i++){
            int val = queries[i][0];
            int idx = queries[i][1];
            if(arr[idx] % 2 == 0){
                sum -= arr[idx];
            }
            arr[idx] += val;
            if(arr[idx]%2==0){
                sum += arr[idx];
            }
            ans[i] = sum;
        }
        
        return ans;
    }
};