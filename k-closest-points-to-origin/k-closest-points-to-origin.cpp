class Solution {
public:
    
    int getDistance(int a, int b){
        return (a*a) + (b*b);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>>ans;
        vector<pair<int, int>>arr;
        for(int i=0; i<n; i++){
            int a = points[i][0], b = points[i][1];
            int dist = getDistance(a, b);
            arr.push_back({dist, i});
        }
        sort(begin(arr), end(arr));
        for(auto &i: arr){
            cout<<i.first<<" "<<i.second<<endl;
        }
        int cnt = 1;
        for(auto &i: arr){
            int a = i.second;
            ans.push_back({points[a][0], points[a][1]});
            if(cnt == k)
                break;
            cnt++;
        }
        return ans;
    }
};