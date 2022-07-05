class Solution
{
    public:
        int longestConsecutive(vector<int> &arr)
        {
            unordered_set<int> s;
            sort(arr.begin(), arr.end());
            int n = arr.size();
            if (n == 0) return 0;
            int ans = 1;
            for (int i = 0; i < n; i++)
            {
                s.insert(arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                int num = arr[i];
                if (s.count(num - 1) == 0)
                {
                    while (s.count(num) == 1)
                    {
                        cnt++;
                        num++;
                    }
                    ans = max(ans, cnt);
                }
            }
            return ans;
        }
};