class Solution {
public:
    
    int climbStairs(int n) {
        if (n==1)
	    	return 1;
        int ans[n+1];
        ans[1] = 1;
        ans[2] = 2;
        for(int i = 3; i<=n; i++)
            ans[i] = ans[i-1]+ans[i-2];
	    return ans[n];
    }
};