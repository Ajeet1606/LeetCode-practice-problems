class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int>map;
        for(auto ch: s)
            map[ch]++;
        
        while(1){
            int maxVal = INT_MIN;
            char ch;
            for(auto x: map){
                if(x.second > maxVal){
                    maxVal = x.second;
                    ch = x.first;
                }
            }
            if(maxVal==0) break;
            for(int i = 0; i < maxVal; i++)
                res.push_back(ch);
            map[ch] = 0;
        }
        return res;
    }
};