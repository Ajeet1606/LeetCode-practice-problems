class Solution {
public:
    #define ll long long
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll>ans(n, 0);
        unordered_map<ll, pair<ll, ll>>left, right;
        for(int i=0; i<n; i++){
            ll leftCnt = left[arr[i]].first;
            ll leftSum = left[arr[i]].second;
            ans[i] += leftCnt*i - leftSum;
            left[arr[i]].first += 1;
            left[arr[i]].second += i;
        }
        
        for(int i= n-1; i>=0; i--){
            ll rightCnt = right[arr[i]].first;
            ll rightSum = right[arr[i]].second;
            ans[i] += rightSum - rightCnt*i;
            right[arr[i]].first+=1;
            right[arr[i]].second += i;
        }
        
        return ans;
    }
};