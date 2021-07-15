class Solution {
public:
    int mySqrt(int x) {
        long long i = 0, ans = 0;
        while(ans <= x){
            i++;
            ans = i*i;
        }
        if(ans==x) return i;
        return i-1;
    }
};