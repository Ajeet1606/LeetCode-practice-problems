class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n == 1){
            return tokens[0] < power;
        }
        sort(tokens.begin(), tokens.end());
        int l=0, r = n-1;
        int score = 0, ans = 0;
        while(l<r){
            //give power
            while(tokens[l] <= power){
                power -= tokens[l++];
                score++;
            }
            ans = max(ans, score);
            //take power
            while(power < tokens[l] and score > 0){
                power += tokens[r--];
                score--;
            }
            if(l == 0 and r == n-1) break;
        }
        return ans;
    }
};