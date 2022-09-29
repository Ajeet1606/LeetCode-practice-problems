//Space optimized
class Solution {
public:    
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        int prev2 = 0, prev = arr[0];
        
        for(int i=1; i<n; i++){
            int take = arr[i] + prev2;
            
            int skip = prev;
            
            int curr = max(take, skip);
            prev2 = prev;
            prev = curr;
        }    
        
        return prev;
    }
};