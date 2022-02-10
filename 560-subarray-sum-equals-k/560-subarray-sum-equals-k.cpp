class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0; // cumulated sum
        unordered_map<int,int> map; // prefix sum recorder
        int cnt = 0; // number of found subarray
        map[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cnt += map[sum-k];
            map[sum]++;
        }
        return cnt;
    }
};