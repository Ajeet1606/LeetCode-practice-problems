class Solution {
public:
    int fourSumCount(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, vector<int>& arr4) {
        int n1 = arr1.size(), n2= arr2.size(), n3 = arr3.size(), n4 = arr4.size();
        int ans = 0;
        unordered_map<int, int>mp;
        
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                mp[arr1[i]+arr2[j]]++;
            }
        }
        for(int i=0; i<n3; i++){
            for(int j=0; j<n4; j++){
                ans += mp[-(arr3[i]+arr4[j])];
            }
        }
        return ans;
    }
};