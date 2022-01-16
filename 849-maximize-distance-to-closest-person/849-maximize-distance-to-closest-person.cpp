class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        int n = arr.size();
        int prev = -1, future = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                prev = i;
            }
            else{
                while(future < n and arr[future]==0 or future < i)
                    future++;
                int left = prev == -1? n: i-prev;
                int right = future == n? n: future-i;
                ans = max(ans, min(left, right));
            }
        }
        return ans;        
    }
};