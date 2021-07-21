class Solution {
public:
    string sortSentence(string s) {
        string ans;
	    char x = '1';
    	while(1)
	    {
		    int found = s.find(x);
    		if (found == string::npos)
	    	{
		    	break;
    		}
	    	int j = found, stIdx = 0;
		    while(j>=0)
		    {
			    if (s[j] ==' ')
    			{
	    			stIdx = j+1;
		    		break;
			    }j--;
		    }
    		for (int i = stIdx; i < found; ++i)
	    	{
		    	ans.push_back(s[i]);
	    	}ans.push_back(' ');
		    x++;
	    }
        ans.erase(ans.begin()+ans.length()-1);
        return ans;
    }
};