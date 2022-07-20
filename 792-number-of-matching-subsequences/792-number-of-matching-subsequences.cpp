class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        //mappings is used to store the indexes of every character in s.
        vector<vector<int>> mappings(26); 
        for(int i = 0; i < size(s); i++) mappings[s[i] - 'a'].push_back(i);
        //we'll check that whether curr char of word is present in s after previous char(check by idx).
        for(auto& word : words) {
            bool found = true;
            //prev is index of previous char of word.
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                //we get a vector of indexes of curr character.
                auto& v = mappings[word[i]-'a'];
                // in this vector there should be any value > prev.
                auto it = upper_bound(begin(v), end(v), prev);   
                if(it == end(v)) found = false;
                //update prev.
                else prev = *it;                       
            }
            ans += found;
        }
        return ans;
    }
};