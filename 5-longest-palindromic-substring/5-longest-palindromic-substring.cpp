class Solution {
public:
    
    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++; r--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int len = s.length(), ans = 0, st;
        if(len==1) return s;
        for(int i = 0; i < len; i++){
            for(int j = len-1; j>=0; j--){
                if(isPalindrome(s, i, j)){
                    if(ans< j-i+1){
                        ans = j-i+1;
                        st = i;
                        break;
                    }
                }
            }
        }
        string res = s.substr(st, ans);
        return res;
    }
};