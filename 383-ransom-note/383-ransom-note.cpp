class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>m;
        for(auto a: magazine){
            m[a]++;
        }
        
        for(auto a: ransomNote){
            if(m[a] > 0){
                m[a]--;
            }else{
                return false;
            }
        }
        return true;
    }
};