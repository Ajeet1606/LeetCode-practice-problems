class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' and s[i]<='z'){
                str.push_back(s[i]);
            }
            else if(s[i]>='A' and s[i]<='Z'){
                str.push_back(s[i]+32);
            }
            else if(s[i]>='0' and s[i]<='9'){
                str.push_back(s[i]);
            }
        }
        
        cout<<str<<endl;
        int l = 0, r = str.length()-1;
        if(r==-1)
            return true;
        while(l<=r){
            if(str[l] != str[r]){
                break;
            }
            l++; r--;
        }
        cout<<l<<r;
        if(l < r)
            return false;
        else
            return true;
    }
};