class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1, high = 1LL* *min_element(time.begin(), time.end()) * totalTrips;
        int n = time.size();
        
        long long ans = 1e18;
        while(low <= high){
            long long mid = low + (high - low)/2;
            //now we check if we can complete totalTrips in mid time.
            // cout<<mid<<' ';
            long long total = 0;
            
            for(int i=0; i<n; i++){
                total += mid/time[i];
                if(total >= totalTrips){
                    break;
                }
            }
            // cout<<total<<endl;
            if(total >= totalTrips){
                ans = min(ans, mid);
                high = mid - 1;
            }else if(total < totalTrips){
                low = mid+1;
            }
        }
        return ans;
    }
};