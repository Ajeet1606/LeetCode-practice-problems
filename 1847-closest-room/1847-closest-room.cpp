class Solution {
    vector<int> ans;
    set<int> s;
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n=rooms.size(),q=queries.size(),i,j,k;
        ans.clear();
        ans.resize(q,-1);
        for(i=0;i<n;i++)swap(rooms[i][0],rooms[i][1]);
        sort(rooms.begin(),rooms.end());
        reverse(rooms.begin(),rooms.end());
        for(i=0;i<q;i++)
        {
            swap(queries[i][0],queries[i][1]);
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end());
        reverse(queries.begin(),queries.end());
        s.clear();
        for(i=j=0;i<q;i++)
        {
            k=queries[i][2];
            for(;j<n&&rooms[j][0]>=queries[i][0];j++)s.insert(rooms[j][1]);
            auto it=s.lower_bound(queries[i][1]);
            if(it!=s.end())ans[k]=*it;
            if(it!=s.begin())
            {
                it--;
                if(!~ans[k]||ans[k]-queries[i][1]>=queries[i][1]-*it)ans[k]=*it;
            }
        }
        return ans;
    }
};