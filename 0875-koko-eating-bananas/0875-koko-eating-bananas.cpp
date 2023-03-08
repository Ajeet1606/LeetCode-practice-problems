class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        long high = 1L * *max_element(piles.begin(), piles.end()) * n;
        // cout<<high<<endl;
        long ans = INT_MAX;
        
        while(low <= high){
            long mid = low + (high - low)/2;
            // cout<<mid<<' ';
            //check validity of mid.
            if(isEnough(piles, mid, h)){
                ans = min(ans, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    bool isEnough(vector<int>&piles, long speed, int h){
        int time_needed = 0;
        // cout<<speed<<' ';
        for(int i=0; i<piles.size(); i++){
            int time = (piles[i] + speed -1) / speed;
            // cout<<time<<' ';
            time_needed += time;
        }
        // cout<<endl;
        if(time_needed <= h) return true;
        return false;
    }
};