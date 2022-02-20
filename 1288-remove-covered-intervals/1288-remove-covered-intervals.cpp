class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n = a.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(a[i][0] == -1) continue;
            for(int j=0; j<n; j++){
                if(j == i) continue;
                if(a[i][0] <= a[j][0] and a[i][1] >= a[j][1]){
                    cnt++;
                    a[j][0] = -1;
                }
            }
        }
        return n-cnt;
    }
};