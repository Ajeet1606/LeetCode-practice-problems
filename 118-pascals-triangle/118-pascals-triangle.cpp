class Solution {
public:
    //top-down dp.
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        //helper function.
        solve(n, ans);
        return ans;
    }
    
    void solve(int n, vector<vector<int>>&ans){
        //base case, for n=0, we've to do nothing 
        if(n == 0) return;
        //go to top(n=1)
        solve(n-1, ans);
        //every step has n size array, fill with 1.
        vector<int>row(n, 1);
        //add in final answer array.
        ans.push_back(row);
        //update mid values
        for(int i=1; i<n-1; i++){
            //we'll do n-1, cz for nth row idx in array will be n-1.
            ans[n-1][i] = ans[n-2][i-1]+ ans[n-2][i];
        }
    }
};