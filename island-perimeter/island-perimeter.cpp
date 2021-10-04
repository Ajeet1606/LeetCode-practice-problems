class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land = 0, share = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				land++;
				if(i!=0 && grid[i-1][j] == 1) share++;
				// check if it shares any side with it's upper cell
                if(j!=0 && grid[i][j-1] == 1) share++;
                // check if it shares any side with it's left cell
			}
		}
	}
	return (4*land)-(share*2);
    }
};