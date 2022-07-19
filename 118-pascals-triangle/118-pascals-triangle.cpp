class Solution {
public:
    vector<vector<int>> generate(int n) {
        //vector to store answer, n size for every row, column side will be decided dynamically.
        vector<vector<int>>ans(n);
        //for every row.
        for(int i=0; i<n; i++){
            //ith row will have i+1 elements(starting from 0), create and initialize with 1.
            ans[i] = vector<int>(i+1, 1);
            //we'll update mid elements [1, i-1]
            for(int j=1; j<i; j++){
                //every element will be sum of it's two upper elements.
                ans[i][j] = ans[i-1][j-1]+ ans[i-1][j];
            }
        }
        //we're done.
        return ans;
    }
};