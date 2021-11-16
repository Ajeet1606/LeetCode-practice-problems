class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while(l<r){
            auto mid = l + (r-l)/2, pos = 0;
            for(int i=1; i<=m; i++)
                pos += min(mid/i, n);
            if(pos < k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};