class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>word;
        for(int i = 0; i<s.length(); i++){
            string t;
            while(s[i]!=' ' && i<s.length()){
                t.push_back(s[i]);
                i++;
            }
            word.push_back(t);
        }
        if(word.size()!=pattern.length()) return false;
        int n = word.size();
        unordered_set<string>set1;
        for(int i = 0; i<n; i++){
            set1.insert(word[i]);
        }
        unordered_map<char, string>map;
        for(int i = 0; i < n; i++){
            if(map.count(pattern[i])==0)
                map[pattern[i]]=word[i];
            else{
                if(map[pattern[i]]!=word[i])
                    return false;
            }
        }
        if(set1.size()!=map.size())
            return false;
        return true;
    }
};