class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> ans(len1);
        for(int i = 0; i<len1; i++){
            int idx;
            for(int j = 0; j<len2; j++){
                if(nums1[i]==nums2[j]){
                    idx = j;
                    break;
                }
            }
            int j;
            for(j = idx; j < len2; j++){
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
            if(j==len2)
                ans[i]=-1;
        }
        return ans;
    }
};