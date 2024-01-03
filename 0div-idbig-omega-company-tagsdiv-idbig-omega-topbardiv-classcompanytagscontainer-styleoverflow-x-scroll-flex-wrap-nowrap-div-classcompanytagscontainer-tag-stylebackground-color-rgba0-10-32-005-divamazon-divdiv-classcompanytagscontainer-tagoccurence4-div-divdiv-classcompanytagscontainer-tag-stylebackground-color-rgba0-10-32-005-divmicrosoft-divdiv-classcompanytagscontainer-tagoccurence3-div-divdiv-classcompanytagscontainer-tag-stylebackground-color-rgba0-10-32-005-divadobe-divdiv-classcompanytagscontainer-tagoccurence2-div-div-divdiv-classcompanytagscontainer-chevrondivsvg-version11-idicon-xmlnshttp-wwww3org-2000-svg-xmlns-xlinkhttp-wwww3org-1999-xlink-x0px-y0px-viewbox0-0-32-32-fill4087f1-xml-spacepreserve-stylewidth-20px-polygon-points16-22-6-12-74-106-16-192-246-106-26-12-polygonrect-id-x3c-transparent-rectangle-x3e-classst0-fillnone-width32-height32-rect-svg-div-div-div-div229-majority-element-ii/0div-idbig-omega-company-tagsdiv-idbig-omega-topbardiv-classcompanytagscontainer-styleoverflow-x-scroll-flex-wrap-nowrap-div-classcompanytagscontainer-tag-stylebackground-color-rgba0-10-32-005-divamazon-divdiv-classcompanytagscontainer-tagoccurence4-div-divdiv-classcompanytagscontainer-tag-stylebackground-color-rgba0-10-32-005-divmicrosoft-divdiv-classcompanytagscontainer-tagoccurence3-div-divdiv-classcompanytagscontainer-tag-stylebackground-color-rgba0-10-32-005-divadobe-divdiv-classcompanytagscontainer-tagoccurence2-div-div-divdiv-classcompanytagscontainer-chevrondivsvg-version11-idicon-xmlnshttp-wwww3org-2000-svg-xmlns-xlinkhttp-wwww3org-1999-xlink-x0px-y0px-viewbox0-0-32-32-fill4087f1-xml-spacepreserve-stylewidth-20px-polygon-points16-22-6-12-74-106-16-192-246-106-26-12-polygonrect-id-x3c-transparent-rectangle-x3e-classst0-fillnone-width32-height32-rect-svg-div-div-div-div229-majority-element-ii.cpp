class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        //1. use frequency map
        //2. sort
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>ans;
        
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                cnt++;
            }else{
                if(cnt > n/3) ans.push_back(arr[i-1]);
                cnt=1;
            }
        }
        if(cnt > n/3) ans.push_back(arr.back());
        return ans;
    }
};