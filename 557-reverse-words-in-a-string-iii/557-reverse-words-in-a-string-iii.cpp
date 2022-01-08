class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        for(int i=0; i<n; i++){
            int st = i;
            while(s[i]!=' ' and i<n)
                i++;
            int end = i-1;
            while(st<end){
                swap(s[st++], s[end--]);
            }
        }
        return s;
    }
};