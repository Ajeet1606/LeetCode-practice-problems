class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> f(n, true);
        int i = 0, cnt = n;
        while(cnt > 1){
            for(int j = 0; j < k; j++, i++){
                while(!f[i%n])
                    i++;
            }
            f[(i-1)%n] = false;
            cnt--;
        }
        for(i = 0; !f[i]; i++);
        return i+1;
    }
};