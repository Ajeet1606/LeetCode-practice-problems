class Solution {
public:
    
    vector<int> make_pattern(string str){
        vector<int>ans;
        unordered_map<char, int>map;
        int idx = 1;
        for(auto s: str){
            if(map.find(s) == map.end()){
                map[s] = idx;
                ans.push_back(idx);
                idx++;
            }
            else{
                ans.push_back(map[s]);
            }
        }
        return ans;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        vector<int>p = make_pattern(pattern);
        
        for(auto word: words){
            if(word.size() != pattern.size()){
                continue;
            }
            vector<int>s = make_pattern(word);
            if(p == s){
                ans.push_back(word);
            }
        }
        return ans;
    }
};