class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto &x: nums)
            s.insert(x);
        int ans, minn = INT_MAX, maxx = INT_MIN;
        for(auto &i: nums){
            minn = min(minn, i);
            maxx = max(maxx, i);
        }
        if(minn > 1 || maxx < 0) return 1;
        int i;
        for(i = 1; i<=maxx; i++){
            if(s.count(i)==0 && i>0){
                ans = i;
                break;
            }
        }
        return i;
    }
};