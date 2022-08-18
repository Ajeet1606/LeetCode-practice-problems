class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>map;
        int n = arr.size();
        for(auto a: arr){
            map[a]++;
        }
        vector<int>freq;
        for(auto m: map){
            freq.push_back(m.second);
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        int sum = 0, ans = 0;
        for(auto i: freq){
            if(sum < n/2){
                ans++;
                sum += i;
            }else{
                break;
            }
        }
        return ans;
    }
};