class Solution {
public:
    int fib(int n) {
        if(n == 0) return n;
        if(n == 1)return n;
        int a = 0, b = 1;
        int cnt = 1, c;
        while(cnt < n){
            c = a+b;
            a = b;
            b = c;
            cnt++;
        }
        return c;
    }
};