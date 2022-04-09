class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 and s[i] == ' '){
            i--;
        }
        int cnt = 0;
        while(i>=0 and s[i]!=' '){
            cnt++;
            i--;
        }
        return cnt;
    }
};