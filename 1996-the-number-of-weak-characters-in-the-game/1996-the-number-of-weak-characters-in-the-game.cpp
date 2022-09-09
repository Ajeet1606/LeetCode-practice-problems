class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int max_d[100002] = {}, res = 0;
        
        for(auto &a: arr){
            max_d[a[0]] = max(max_d[a[0]], a[1]);
        }
        
        for(int i=100000; i>0; i--){
            max_d[i-1] = max(max_d[i-1], max_d[i]);
        }
        
        for(auto &a: arr){
            res += max_d[a[0]+1] > a[1];
        }
        
        return res;
    }
};