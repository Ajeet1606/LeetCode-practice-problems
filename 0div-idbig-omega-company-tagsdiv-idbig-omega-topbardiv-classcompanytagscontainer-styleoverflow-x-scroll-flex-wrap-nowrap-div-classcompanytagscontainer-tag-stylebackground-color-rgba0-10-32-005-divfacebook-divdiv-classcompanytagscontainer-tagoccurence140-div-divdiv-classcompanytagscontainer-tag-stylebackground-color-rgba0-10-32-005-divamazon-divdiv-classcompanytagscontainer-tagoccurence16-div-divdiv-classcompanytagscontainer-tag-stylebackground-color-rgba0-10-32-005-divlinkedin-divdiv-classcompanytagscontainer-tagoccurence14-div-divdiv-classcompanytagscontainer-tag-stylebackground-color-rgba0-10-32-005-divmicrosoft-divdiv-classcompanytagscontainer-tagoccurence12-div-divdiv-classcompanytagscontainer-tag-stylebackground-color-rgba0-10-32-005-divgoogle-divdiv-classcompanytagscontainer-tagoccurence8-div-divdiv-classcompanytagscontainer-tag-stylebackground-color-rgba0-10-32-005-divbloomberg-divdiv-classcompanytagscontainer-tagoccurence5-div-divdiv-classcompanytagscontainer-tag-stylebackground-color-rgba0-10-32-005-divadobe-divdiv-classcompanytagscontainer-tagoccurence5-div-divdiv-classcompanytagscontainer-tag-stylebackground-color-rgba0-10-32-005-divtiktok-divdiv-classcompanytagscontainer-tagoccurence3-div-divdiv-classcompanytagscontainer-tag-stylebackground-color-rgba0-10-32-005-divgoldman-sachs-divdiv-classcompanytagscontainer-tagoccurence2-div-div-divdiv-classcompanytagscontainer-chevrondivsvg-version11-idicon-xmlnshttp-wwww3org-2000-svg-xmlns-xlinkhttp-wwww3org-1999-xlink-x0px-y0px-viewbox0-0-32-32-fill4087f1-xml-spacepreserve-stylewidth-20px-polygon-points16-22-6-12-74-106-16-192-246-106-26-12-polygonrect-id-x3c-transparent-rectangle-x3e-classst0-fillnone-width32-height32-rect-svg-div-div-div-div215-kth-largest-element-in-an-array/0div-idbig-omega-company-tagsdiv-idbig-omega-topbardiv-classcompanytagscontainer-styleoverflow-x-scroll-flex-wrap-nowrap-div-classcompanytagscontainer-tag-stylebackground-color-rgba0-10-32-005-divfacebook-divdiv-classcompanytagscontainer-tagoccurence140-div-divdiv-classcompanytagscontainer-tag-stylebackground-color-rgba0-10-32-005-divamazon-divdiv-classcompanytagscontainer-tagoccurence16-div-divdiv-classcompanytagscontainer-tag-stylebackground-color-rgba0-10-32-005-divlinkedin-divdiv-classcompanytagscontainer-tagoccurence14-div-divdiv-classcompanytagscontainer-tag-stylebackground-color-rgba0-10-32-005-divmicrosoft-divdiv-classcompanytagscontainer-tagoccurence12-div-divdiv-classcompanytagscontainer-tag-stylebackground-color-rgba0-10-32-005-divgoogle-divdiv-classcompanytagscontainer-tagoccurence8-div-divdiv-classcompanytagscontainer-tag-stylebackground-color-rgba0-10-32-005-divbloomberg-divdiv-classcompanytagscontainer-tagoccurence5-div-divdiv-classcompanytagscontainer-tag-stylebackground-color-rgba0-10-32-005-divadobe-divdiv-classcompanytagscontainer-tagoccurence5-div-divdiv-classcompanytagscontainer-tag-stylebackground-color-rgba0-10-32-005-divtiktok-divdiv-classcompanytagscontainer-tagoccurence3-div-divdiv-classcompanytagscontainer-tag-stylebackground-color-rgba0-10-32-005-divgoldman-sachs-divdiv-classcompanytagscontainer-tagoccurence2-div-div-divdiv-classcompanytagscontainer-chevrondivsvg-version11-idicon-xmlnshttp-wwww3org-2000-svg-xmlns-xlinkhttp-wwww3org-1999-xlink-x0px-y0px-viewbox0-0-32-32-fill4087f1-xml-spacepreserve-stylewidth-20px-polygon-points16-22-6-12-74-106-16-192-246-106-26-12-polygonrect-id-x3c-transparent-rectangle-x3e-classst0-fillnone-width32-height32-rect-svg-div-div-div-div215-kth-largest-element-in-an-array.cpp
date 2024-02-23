class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        
        while(pq.size() > k) pq.pop();
        return pq.top();
    }
};