class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a1(26, 0), a2(26, 0);
        for(auto i: s){
            a1[i-'a']++;
        }
        for(auto i: t){
            a2[i-'a']++;
        }
        
        int i=0; 
        while(i<26 and a1[i] == a2[i]){
            i++;
        }
        
        return i==26;
    }
};