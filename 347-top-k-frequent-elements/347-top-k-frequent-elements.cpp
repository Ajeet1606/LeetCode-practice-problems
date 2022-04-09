class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<int, int>>p;
        sort(begin(arr), end(arr));
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(i<n-1 and arr[i] == arr[i+1]){
                i++;
                cnt++;
            }
            p.push({cnt, arr[i]});
        }
        
        vector<int>ans;
        while(!p.empty() and k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};