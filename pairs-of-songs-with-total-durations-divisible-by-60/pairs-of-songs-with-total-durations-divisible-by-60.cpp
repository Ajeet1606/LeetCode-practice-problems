class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int>mp;
        int n = time.size();
        
        for(int i=0; i<n; i++){
            time[i] = time[i]%60;
            mp[time[i]]++;
        }
        for(auto x: mp){
            if(x.first == 0 or x.first == 30){
                ans += ((x.second - 1)*x.second)/2;
            }
            else if(x.first < 30 and mp.count(60 - x.first)){
                ans += x.second * mp[60- x.first];
            }
        }
        return ans;
    }
};