class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& query) {
        std::vector<int> ans(query.size());
	    for (int i = 0; i < query.size(); ++i)
	    {
		    int c1 = query[i][0], c2 = query[i][1], r = query[i][2], cnt = 0;

    		for (int i = 0; i < points.size(); ++i)
	    	{
		    	int x = points[i][0], y = points[i][1];
    			int dis = pow((c1 - x), 2) + pow((c2 - y), 2);
    			if (dis <= r*r) cnt++;
	    	}
    		ans[i] = cnt;
	    }
        return ans;
    }
};