class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int i=0, j=0;
        while(i<n1 and j<n2){
            char ch = s[i];
            
            while(j<n2 and t[j] != ch){
                j++;
            }
            if(j<n2) i++;
            if(t[j] == ch) j++;
        }
        if(i==n1){
            return true;
        }
        else return false;
    }
};