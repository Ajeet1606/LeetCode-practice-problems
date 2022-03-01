class Solution {
public:
    
    int solve(int n, vector<int>&memo){
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(memo[n] != 0) return memo[n];
        if(n%2 == 0){
            memo[n] = solve(n/2, memo);
            return solve(n/2, memo);
        }
        else{
            memo[n]= 1+ solve(n/2, memo);
            return 1+ solve(n/2, memo);
        }
    }
    
    vector<int> countBits(int n) {
        vector<int>a(n+1);
        for(int i=0; i<=n; i++){
            a[i] = solve(i, a);
        }
        return a;
    }
};