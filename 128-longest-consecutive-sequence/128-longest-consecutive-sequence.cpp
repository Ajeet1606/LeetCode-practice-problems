class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int>s;
        sort(arr.begin(), arr.end()); //nlogn
        int n = arr.size();
        if(n==0) return 0;
        int ans = 1;
        for(int i=0; i<n;){
            int cnt = 1, j;
            for(j=i; j<n-1; j++){
                if(arr[j] == arr[j+1]){
                    continue;
                }
                if(arr[j] == arr[j+1]-1){
                    cnt++;
                }
                else{
                    break;
                }
            }
            i=j+1;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};