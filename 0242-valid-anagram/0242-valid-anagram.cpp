class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if(len1 != len2) return false;
        
        int count[26] = {0};
        
        for(int i=0; i<len1; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(count[i]) return false;
        }
        return true;
    }
};