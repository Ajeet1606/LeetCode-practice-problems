class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int, int>map;
        for(int x: arr)
            map[x]++;
        vector<int>res;
        for(auto x: map){
            if(x.second>1)
                res.push_back(x.first);
        }
        return res;
    }
};