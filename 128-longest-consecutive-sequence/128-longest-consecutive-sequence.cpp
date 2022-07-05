class Solution
{
    public:
        int longestConsecutive(vector<int> &arr)
        {
            unordered_set<int> s;
            sort(arr.begin(), arr.end());	//nlogn
            int n = arr.size();
            if (n == 0) return 0;
            int ans = 1, cnt = 1;
            for (int i = 0; i < n - 1; i++){
                if (arr[i] == arr[i + 1]){
                    continue;
                }
                if (arr[i] == arr[i + 1] - 1){
                    cnt++;
                }
                else{
                    ans = max(ans, cnt);   
                    cnt = 1;
                }
            }
            ans = max(ans, cnt);
            return ans;
        }
};