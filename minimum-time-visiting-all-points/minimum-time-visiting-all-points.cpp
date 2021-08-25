class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size()-1; i++){
            for(int j = 0; j < points[0].size()-1; j++){
                res += max(abs(points[i+1][0] - points[i][0]), abs(points[i+1][1] - points[i][1]));
            }
        }
        return res;
    }
};