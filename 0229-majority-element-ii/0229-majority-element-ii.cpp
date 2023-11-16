class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
//         brute: use map, TC: O(n), SC: O(n)
//         better in space: sort, O(nlogn), SC: O(1)
        
        int n = arr.size(), cnt = 1;
        if(n == 1) return arr;
        
        sort(arr.begin(), arr.end());
        vector<int>ans;
        
        for(int i=1; i<n; i++){
            while(i < n and arr[i-1] == arr[i]){
                cnt++, i++;
            }
            if(cnt > n/3){
                ans.push_back(arr[i-1]);
            }
            cnt = 1;
        }
        if(cnt > n/3 and ans.back() != arr[n-1]){
            ans.push_back(arr[n-1]);
        }
        
        return ans;
    }
};