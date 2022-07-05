class Solution
{
    public:
        int longestConsecutive(vector<int> &arr)
        {
            unordered_set<int> s;
           // sort(arr.begin(), arr.end());
            int n = arr.size();
            if (n == 0) return 0;
            int ans = 1;
            for (int i = 0; i < n; i++)
            {
                s.insert(arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                int right = arr[i]+1;
                int left = arr[i]-1;
                while(s.erase(left)){
                    left--;
                }
                while(s.erase(right)){
                    right++;
                }
                ans = max(ans, right - left - 1);
                if(s.empty())
                    return ans;
            }
            return ans;
        }
};