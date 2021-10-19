class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>ans;
        unordered_map<int, int>map;
        for(int x: nums2){
            while(s.size() && s.top() < x){
                map[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for(auto n: nums1){
            ans.push_back(map.count(n) ? map[n] : -1);
        }
        return ans;
    }
};