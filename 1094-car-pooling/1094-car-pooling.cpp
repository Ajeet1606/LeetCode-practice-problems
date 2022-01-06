class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {0};
        for(auto t: trips){
            stops[t[1]] += t[0];
            stops[t[2]] -= t[0];
        }
        
        for(auto c: stops){
            capacity -= c;
            if(capacity < 0)
                return false;
        }
        
        return capacity >= 0;
    }
};