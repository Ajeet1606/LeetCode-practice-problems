class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        int ans = 0, mx = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(arr[i][1] < mx){
                ans++;
            }else{
                mx = max(mx, arr[i][1]);
            }
        }
        return ans;
    }
};