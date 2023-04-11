class Solution {
public:
    string removeStars(string str) {
        string ans;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '*'){
                ans.pop_back();
            }else{
                ans.push_back(str[i]);
            }
        }
        
        return ans;
    }
};