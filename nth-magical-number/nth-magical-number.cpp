class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int l = a/ __gcd(a, b) * b;
        int m = l/a + l/b - 1;
        int q = n/m, r = n%m;
        long ans = (long)q* l%MOD;
        if(r==0)
            return (int)ans;
        int heads[2] = {a, b};
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += a;
            else
                heads[1] += b;
        }

        ans += min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }
};