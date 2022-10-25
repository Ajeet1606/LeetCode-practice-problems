class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first, second;
        
        for(auto word: word1){
            first += word;
        }
        
        for(auto word: word2){
            second += word;
        }
        
        
        return first == second;
    }
};