class Solution {
public:
    vector<string>m;
    
    Solution(){
        m.resize(26);
        m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>s;
        for(auto word: words){
            string str = "";
            for(auto w: word){
                str += m[w - 'a'];
            }
            s.insert(str);
        }
        return s.size();
    }
};