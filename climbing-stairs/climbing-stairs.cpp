class Solution {
public:
    
    int climbStairs(int n) {
        if (n==1)
	    	return 1;
        int res[n+1];
        res[0] = 0;
        res[1]= 1;
        res[2]=2;
        for(int i = 3; i <= n; i++){
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];
    }
};