class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        unordered_map<char, int> end;
        for(int i = s.length()-1; i >= 0; i--){
            if(end.count(s[i])==0)
                end[s[i]] = i;
        }
        for(int i = 0; i < s.length(); i++){
            int st = i, last = end[s[i]];
            int j = st+1;
            while(j<last){
                if(end[s[j]]>last)
                    last = end[s[j]];
                j++;
            }
            res.push_back(last-st+1);
            i = last;
        }
        return res;
    }
};