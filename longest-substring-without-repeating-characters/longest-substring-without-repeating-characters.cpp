class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len==1) return 1;
        unordered_set<char>set;
        int res = 0;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                if(set.count(s[j])==0)
                    set.insert(s[j]);
                else{
                    int n = set.size();
                    res = max(res, n);
                    set.clear();
                    break;
                }
            }
        }
        return res;
    }
};