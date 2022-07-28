class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26, 0);
        for(auto i: s){
            a[i-'a']++;
        }
        for(auto i: t){
            a[i-'a']--;
        }
        
        int i=0; 
        while(i<26 and a[i] == 0){
            i++;
        }
        
        return i==26;
    }
};