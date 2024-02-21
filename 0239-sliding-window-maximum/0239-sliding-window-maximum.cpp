class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0; i<n; i++){
            //pop the number from front who's out of window size.
            if(!dq.empty() and dq.front() == i-k) dq.pop_front();
            //pop number from back who's smaller than new number.
            while(!dq.empty() and nums[dq.back()] < nums[i])
                dq.pop_back();
            //insert current into deque
            dq.push_back(i);
            //if window size is k now, insert front into answer.
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};