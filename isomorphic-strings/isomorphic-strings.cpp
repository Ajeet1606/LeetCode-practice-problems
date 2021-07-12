class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map;
	    unordered_set<int> mapped;
    	if (s.size() != t.size())
	    {
		    return false;
    	}
	    for (int i = 0; i < s.size(); ++i)
	    {
		    int cs = s[i], ct = t[i];
    		if (map.count(cs))
	    	{
		    	if (map[cs]==ct) continue;
			    else return false;			
		    }
    		else{
	    		if (mapped.count(ct)) return false;
		    	map[cs] = ct;
			    mapped.insert(ct);
    		}
	    }
	    return true;
    }
};