class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>map;
        for(auto &a: arr){
            map[a]++;
        }
        
        priority_queue<int>pq;
        for(auto [key, val]: map){
            pq.push(val);
        }
        
        int sum = 0, ans = 0, half = arr.size()/2;
        while(sum < half and !pq.empty()){
            sum += pq.top();
            ans++;
            pq.pop();
        }
        return ans;
    }
};