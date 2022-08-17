class Solution {
public:
    vector<string>m;
    
    Solution(){
        m.resize(26);
        m[0] = ".-";
        m[1] = "-...";
        m[2] = "-.-.";
        m[3] = "-..";
        m[4] = ".";
        m[5] = "..-.";
        m[6] = "--.";
        m[7] = "....";
        m[8] = "..";
        m[9] = ".---";
        m[10] = "-.-";
        m[11] = ".-..";
        m[12] = "--";
        m[13] = "-.";
        m[14] = "---";
        m[15] = ".--.";
        m[16] = "--.-";
        m[17] = ".-.";
        m[18] = "...";
        m[19] = "-";
        m[20] = "..-";
        m[21] = "...-";
        m[22] = ".--";
        m[23] = "-..-";
        m[24] = "-.--";
        m[25] = "--..";
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