class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<char, int>mp;
        int n = strs.size();
        
        string ans;
        
        for(int i=0; i<strs[0].length(); i++){
//             check if each string has the same char at same index.
            bool ok = true;
            
            for(int j=1; j<n; j++){
                if(i >= strs[j].length() or strs[j][i] != strs[0][i]){
                    ok = false;
                    break;
                }
            }
            
            if(ok){
                ans.push_back(strs[0][i]);
            }else{
                break;
            }
        }
        return ans;
        
    }
};