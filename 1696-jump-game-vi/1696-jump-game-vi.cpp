class Solution
{
    public:
       	//optimized dp
        int maxResult(vector<int> &arr, int k)
        {
           	//make dp array.
            vector<int> dp(size(arr), INT_MIN);
           	//initialise dp[0] = arr[0] 
            dp[0] = arr[0];
            deque<int> q
            { 0 };
           	// traverse arr.
            for (int i = 1; i < size(arr); i++){
                if (q.front() < i - k) q.pop_front();	// can't reach current index from index stored in q     
                dp[i] = arr[i] + dp[q.front()];	// update max score for current index
                while (!q.empty() && dp[q.back()] <= dp[i])	// pop indices which won't be ever chosen in the future
                    q.pop_back();
                q.push_back(i);	// insert current index
            }
           	//last value of dp is ans.
            return dp.back();
        }
};