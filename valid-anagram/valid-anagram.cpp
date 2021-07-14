class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        bool ans = true;
        int map[26] = {0}, map1[26] = {0};
        for(int i = 0; i < s.length(); i++){
            map[s[i]-'a']++;
            map1[t[i]-'a']++;
        }
        
        for(int i = 0; i<26; i++)
            if(map[i]!=map1[i])
                return false;
        return true;
        
    }
};