class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans = str[0];
        for(int i =1; i < str.size(); i++)
        {
            int j;
            for(j = 0; j < str[i].size(); j++){
                if(ans[j]!=str[i][j])
                    break;
            }
            ans = ans.substr(0, j);
            if(ans==" ") return ans;           
        }
        return ans;
    }
};