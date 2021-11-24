class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int len1 = firstList.size(), len2 = secondList.size();
        if(len1 == 0 || len2 == 0) return {};
        vector<vector<int>>res;
        int i=0, j=0;
        while(i<len1 && j<len2){
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];
            if(s2<=e1 && e2>=s1){
                int a1 = max(s1, s2), a2 = min(e1, e2);
                res.push_back({a1, a2});
            }
            if(e2>e1) i++;
            else j++;
        }
        return res;
    }
};