class Solution
{
    public:
        int candy(vector<int> &arr)
        {
            int n = arr.size();
            vector<int> candy(n, 1);
            int ans = 0;

            // forward comparsion.
            for (int i = 1; i < n; i++){
                if(arr[i] > arr[i-1]){
                    candy[i] = candy[i-1]+1;
                }
            }
            
            //backward comparison.
            for(int i=n-2; i>=0; i--){
                if(arr[i] > arr[i+1]){
                    //might be candy[i] > candy[i+1] cz of previous change so we'll take maximum.
                    candy[i] = max(candy[i], candy[i+1]+1);
                }
            }

            // sum up.
            for (int i = 0; i < n; i++){
                ans += candy[i];
            }

            return ans;
        }
};
// O(n) time and O(n) space.