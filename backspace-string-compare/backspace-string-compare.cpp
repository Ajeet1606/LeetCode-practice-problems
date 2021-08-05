class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st, st2;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]>='a' && s[i]<='z')
		{
			st.push(s[i]);
		}
		else if(!st.empty())
			st.pop();
	}
	for (int i = 0; i < t.length(); ++i)
	{
		if (t[i]>='a' && t[i]<='z')
		{
			st2.push(t[i]);
		}
		else if(!st2.empty())
			st2.pop();
	}
	if (st==st2)
	{
		return true;
	}
	else
		return false;
    }
};