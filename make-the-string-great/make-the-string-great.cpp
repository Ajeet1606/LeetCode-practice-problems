class Solution {
public:
    string makeGood(string s) {
        string ans;
        stack<char>st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(st.empty())
                st.push(s[i]);
            else {
                char c1 = st.top();
                char c2 = s[i];
                if(max(c1, c2) - 32 == min(c1, c2))
                    st.pop();
                else
                    st.push(c2);
            }
        }
        bool isEmpty = false;
        while(!st.empty()){
            isEmpty = true;
            ans.push_back(st.top());
            st.pop();
        }
        if(isEmpty)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};