class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int>mp;
        for(auto a: A){
            for(auto b: B){
                mp[a+b]++;
            }
        }
        
        for(auto c: C){
            for(auto d: D){
                ans += mp[-c-d];
            }
        }
        
        return ans;
    }
};