class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        //as n < h, so high is only *max_element.
        int high = *max_element(piles.begin(), piles.end());
        // cout<<high<<endl;
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = low + (high - low)/2;
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
    
    bool isEnough(vector<int>&piles, int speed, int h){
        long time_needed = 0;
        // cout<<speed<<' ';
        for(auto p: piles){
            time_needed += (p + speed -1) / speed;
        }
        // cout<<endl;
        if(time_needed <= h) return true;
        return false;
    }
};