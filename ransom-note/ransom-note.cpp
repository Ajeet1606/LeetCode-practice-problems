class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.length();
        int n = magazine.length();
        if(n < m) return false;
        vector<int>ransom(26), mag(26);
        for(int i = 0; i<m; i++)
            ransom[ransomNote[i]-'a']++;
        for(int i = 0; i<n; i++)
            mag[magazine[i]-'a']++;
        
        for(int i = 0; i<26; i++){
            if(ransom[i]> mag[i])
                return false;
        }
        return true;
    }
};