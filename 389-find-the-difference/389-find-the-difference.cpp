class Solution {
public:
    char findTheDifference(string s, string t) {
        // Sum of ASCII values
        char sum = t[t.length()-1];
        for(int i=0; i<s.length(); i++){
            sum += t[i];
            sum -= s[i];
        }
        return sum;
    }
};