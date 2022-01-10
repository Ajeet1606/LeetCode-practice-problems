class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_set<char>set;
        int res = 0, i=0, j=0;
        while(i<len && j<len){
            if(set.count(s[j])==0){
                set.insert(s[j++]);
                res = max(res, j-i);
            }
            else{
                set.erase(s[i++]);
            }
        }
        return res;
    }
};