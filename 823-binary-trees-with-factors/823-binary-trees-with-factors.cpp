class Solution {
public:
    const int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long>m;
        unordered_set<int>s;
        for(auto a: arr){
            s.insert(a);
            m[a] = 1;
        }
        sort(begin(arr), end(arr));
        int ans = 0;
        for(int idx = 0; idx < arr.size(); idx++){
            for(int j=0; j<idx; j++){
                if(arr[idx] % arr[j] == 0){
                    int sec = arr[idx] / arr[j];
                    if(s.count(sec) == 1)
                        m[arr[idx]] = (m[arr[idx]] + m[arr[j]] * m[sec]) % MOD;
                }
            }
            
        }
        for(auto a: arr){
            ans = (ans%MOD + m[a]%MOD) % MOD;
        }
        return ans%MOD;
    }
};