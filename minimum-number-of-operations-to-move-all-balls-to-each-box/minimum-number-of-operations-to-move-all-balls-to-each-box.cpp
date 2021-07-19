class Solution {
public:
    vector<int> minOperations(string str) {
        int len = str.length();
	    vector<int> ans(len);
    	for (int i = 0; i < len; ++i)
	    {
		    int cnt=0;
		    for (int j = 0; j < len; ++j)
		    {
			    if(str[j]=='1' && j!=i) cnt += abs(j-i);
		    }
    		ans[i] = cnt;
	    }
        return ans;
    }
};