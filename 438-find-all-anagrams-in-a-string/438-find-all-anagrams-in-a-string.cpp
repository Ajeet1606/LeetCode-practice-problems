class Solution {
public:
    int freq[26] = {0};
    string str;
    int len;
    bool isAnagram(int idx){
        int a[26];
        for(int i=0; i<26; i++)
            a[i] = freq[i];
        for(int i=0; i<len; i++){
            a[str[idx++]-'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(a[i]!= 0)
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        str = s;
        len = p.length();
        if(len > s.length()) return {};
        for(int i=0; i<len; i++)
            freq[p[i]-'a']++;
        
        vector<int>ans;
        for(int i=0; i<=s.length()-len; i++){
            cout<<i;
            if(isAnagram(i))
                ans.push_back(i);
        }
        return ans;
    }
};