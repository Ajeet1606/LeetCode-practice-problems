class Solution {
public:
    int MOD = 1e9+7;
    
    int concatenatedBinary(int n) {
        long long val = 0;
        int num = 1;
        
        while(num <= n){
            val = (((val << (1 + (int)log2(num))) % MOD) + num)% MOD;
            num++;
        }
        
        
        return val % MOD;
    }
};