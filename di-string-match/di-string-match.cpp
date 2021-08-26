class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int l = 0, r = s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='I'){
                ans.push_back(l);
                l++;
            }
            else{
                ans.push_back(r);
                r--;
            }
        }
        ans.push_back(l);
        return ans;
    }
};