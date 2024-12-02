class Solution {
public:
    //using map.
    bool isAnagram(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if(len1 != len2) return false;
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<len1; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(const auto&pair: mp){
            if(pair.second != 0) return false;
        }
        return true;
    }
};