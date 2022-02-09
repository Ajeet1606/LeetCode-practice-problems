class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        int n = a.size();
        if(n==0 or k<0) return 0;
        unordered_map<int, int>mp;
        for(auto i: a)
            mp[i]++;
        int res = 0;
        for(auto x: mp){
            if(k==0){
                if(x.second >= 2)
                    res++;
            }
            else
                res += mp.count(x.first+k);
        }
        return res;
    }
};