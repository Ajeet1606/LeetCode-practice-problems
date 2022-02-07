class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(int i=0; i<s.length(); i++){
            // c ^= s[i]; also works
            c = (char)((int)(c) ^ (int)(s[i]));
        }
        for(int i=0; i<t.length(); i++){
            c = (char)((int)(c) ^ (int)(t[i]));
        }
        return c;
    }
};