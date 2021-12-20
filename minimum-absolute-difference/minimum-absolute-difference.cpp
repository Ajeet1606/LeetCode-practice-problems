class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = INT_MAX, n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++){
            minDiff = min(minDiff, abs(arr[i+1] - arr[i])); // 1 2 3 4
        }
        vector<vector<int>>a;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1]-arr[i]) == minDiff){
                a.push_back({arr[i], arr[i+1]});
            }
        }
        return a;
    }
};