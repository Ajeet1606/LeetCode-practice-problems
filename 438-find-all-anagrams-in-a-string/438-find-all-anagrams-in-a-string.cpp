class Solution {
public:
    int pp[26] = {0}, ss[26] = {0};
    int plen, slen;
    
    bool isEqual(){
        for(int i=0; i<26; i++){
            if(pp[i]!= ss[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        plen = p.length();
        slen = s.length();
        if(plen > slen) return {};
        for(int i=0; i<plen; i++){
            pp[p[i]-'a']++;
            ss[s[i]-'a']++;
        }
        
        vector<int>ans;
        if(isEqual())
                ans.push_back(0);
        for(int i=plen; i<s.length(); i++){
            cout<<i;
            
            ss[s[i]-'a']++;
            ss[s[i-plen]-'a']--;
            if(isEqual())
                ans.push_back(i-plen+1);
        }
        return ans;
    }
};