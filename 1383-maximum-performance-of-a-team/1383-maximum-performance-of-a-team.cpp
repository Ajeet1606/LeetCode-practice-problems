class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {efficiency[i], speed[i]};
        }
        sort(arr.rbegin(), arr.rend());
        priority_queue<int, vector<int>, greater<int>>pq;
        long ans = INT_MIN, sum = 0;
        for(int i=0; i<n; i++){
            int effi = arr[i].first, speed = arr[i].second;
            sum += speed;
            pq.push(speed);
            
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum*effi);
        }
        return ans%MOD;
    }
};