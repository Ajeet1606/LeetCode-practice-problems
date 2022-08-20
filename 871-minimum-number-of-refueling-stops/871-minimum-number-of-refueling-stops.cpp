class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int max_reach = startFuel;
        priority_queue<int>pq;
        
        int ans = 0, idx = 0;
        while(max_reach < target){
            while(idx < stations.size() and stations[idx][0] <= max_reach){
                pq.push(stations[idx][1]);
                idx++;
            }
            if(pq.empty()){
                return -1;
            }
            
            max_reach += pq.top();
            pq.pop();
            ans++;
            
        }
        return ans;
    }
};