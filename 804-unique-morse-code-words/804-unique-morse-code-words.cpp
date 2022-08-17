class Solution {
public:
    unordered_map<char, string>m;
    
    Solution(){
        m['a'] = ".-";
        m['b'] = "-...";
        m['c'] = "-.-.";
        m['d'] = "-..";
        m['e'] = ".";
        m['f'] = "..-.";
        m['g'] = "--.";
        m['h'] = "....";
        m['i'] = "..";
        m['j'] = ".---";
        m['k'] = "-.-";
        m['l'] = ".-..";
        m['m'] = "--";
        m['n'] = "-.";
        m['o'] = "---";
        m['p'] = ".--.";
        m['q'] = "--.-";
        m['r'] = ".-.";
        m['s'] = "...";
        m['t'] = "-";
        m['u'] = "..-";
        m['v'] = "...-";
        m['w'] = ".--";
        m['x'] = "-..-";
        m['y'] = "-.--";
        m['z'] = "--..";
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>s;
        for(auto word: words){
            string str = "";
            for(auto w: word){
                str += m[w];
            }
            s.insert(str);
        }
        return s.size();
    }
};