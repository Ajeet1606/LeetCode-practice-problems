class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> m1, m2;
        for(auto& x: a)
            m1[x]++;
        for(auto& x: b)
            m2[x]++;
        vector<int>v;
        for(auto x: a){
            if(m2.count(x)!=0){
                int cnt = min(m1[x], m2[x]);
                while(cnt--)
                    v.push_back(x);
                m2.erase(x);
            }
        }
        return v;
    }
};