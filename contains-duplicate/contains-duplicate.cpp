class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans = false;
        unordered_set<int>set;
        for(auto &x: nums){
            if(set.count(x)!=0)
            {
                ans = true;
                break;
            }
            set.insert(x);
        }
        return ans;
    }
};