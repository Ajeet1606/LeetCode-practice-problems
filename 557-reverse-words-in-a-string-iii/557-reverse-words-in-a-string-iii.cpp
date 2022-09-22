class Solution {
public:
    string reverseWords(string s) {
        
        int st = 0;
        for(int i=0; i<=s.length(); i++){
            if(i == s.length() or s[i] == ' '){
                int end = i-1;
                while(st < end){
                    swap(s[st], s[end]);
                    st++;
                    end--;
                }
                st = i+1;
            }
        }
        
        return s;
    }
};