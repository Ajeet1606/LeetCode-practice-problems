class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0, n = chargeTimes.size();
        deque<int>dq;
        int j=0;
        long long sum = 0, cost = 0;
        for(int i=0; i<n; i++){
            sum += runningCosts[i];
            while(!dq.empty() and dq.back() < chargeTimes[i]){
                dq.pop_back();
            }
            dq.push_back(chargeTimes[i]);
            cost = dq.front() + (i-j+1)* sum;
            
            while(cost > budget){
                sum -= runningCosts[j];
                if(chargeTimes[j] == dq.front())
                    dq.pop_front();
                cost = dq.front() + (i-j+1)* sum;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};