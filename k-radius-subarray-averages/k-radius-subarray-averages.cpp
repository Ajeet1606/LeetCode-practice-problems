class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long>prefix(n);
        prefix[0] = arr[0];
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1] + arr[i];
        vector<int>res(n, -1);
        int cnt = 2*k+1;
        for(int i=k; i+k<n; i++){
            if(i==k)
                res[i] = prefix[i+k]/cnt;
            else
                res[i] = (prefix[i+k] - prefix[i-k-1])/cnt;
        }
        return res;
    }
};