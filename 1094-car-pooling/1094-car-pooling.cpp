class Solution {
public:
    
    bool static myCmp(const vector<int>&a, const vector<int>&b){
        return a[1] < b[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int cap) {
        int n = trips.size();
        unordered_map<int, int>coming, going;
        
        sort(trips.begin(), trips.end(), myCmp);
        int st = trips[0][1], end = trips[0][2];
        
        for(int i=0; i<n; i++){
            st = min(trips[i][1], st);
            end = max(trips[i][2], end);
            coming[trips[i][1]] += trips[i][0];
            going[trips[i][2]] += trips[i][0];
        }
        
        int currSize = 0;
        for(int i=st; i<=end; i++){
            currSize = currSize + coming[i] - going[i];
            if(currSize > cap){
                return false;
            }
        }
        return true;
    }
};