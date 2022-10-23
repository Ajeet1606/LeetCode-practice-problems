class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int>m;
        for(int i=1; i<=n; i++){
            m[i] = 0;
        }
        for(auto a: arr){
            m[a]++;
        }
        
        int dup = -1, missing = 1;
        
        for(auto [key, val]: m){
            if(val == 2){
                dup = key;
            }
            if(val == 0){
                missing = key;
            }
        }
        
        return {dup, missing};
    }
};