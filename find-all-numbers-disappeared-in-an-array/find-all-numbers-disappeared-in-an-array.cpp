class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>set;
        vector<int>ans;
        int n = nums.size();
        for(auto &x: nums)
            set.insert(x);
        for(int i=1; i<=n; i++){
            if(set.count(i)==0)
                ans.push_back(i);
        }
        return ans;
    }
};