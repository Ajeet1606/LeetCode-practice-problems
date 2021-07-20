class Solution {
public:
    string interpret(string str) {
        for (int i = 0; i < str.length(); ++i)
	    {
            if (str[i]=='(' && str[i+1]==')')
		    {
                str[i]='o';
			    str.erase(i+1, 1);
            }else if (str[i]=='(' && str[i+1]=='a')
		    {
                str[i]='a'; str[i+1]='l';
			    str.erase(i+2, 2);
		    }
	    }
        return str;
    }
};