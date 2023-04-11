class Solution {
public:
    string removeStars(string str) {
        stack<char>st;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '*'){
                st.pop();
            }else{
                st.push(str[i]);
            }
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};