class Solution {
public:
    int arithmeticTriplets(vector<int>& arr, int diff) {
        int ans = 0;
        int n = arr.size();
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        for(int i=0; i<n; i++){
            if(s.find(arr[i]+diff) != s.end() and s.find(arr[i]-diff) != s.end()){
                ans++;
            }
        }
        return ans;
    }
};