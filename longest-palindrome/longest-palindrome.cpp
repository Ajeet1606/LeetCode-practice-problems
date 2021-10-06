class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        if(len==1) return 1;
        unordered_map<char, int>map;
        for(auto ch: s)
            map[ch]++;
        int res = 0;
        bool hasOdd = false;
        for(auto x: map){
            if(x.second%2==0)
                res+= x.second;
            else{
                hasOdd = true;
                if(x.second>1)
                    res += x.second-1;
            }
        }
        if(hasOdd)
            res++;
        return res;
    }
};