//we use binary search to find, if we can achieve X amount of tastiness by using exactly k candies.
class Solution {
public:
    int maximumTastiness(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int l = 0, r = a[n-1];
        while(r >= l){
            int mid = (l + r) >> 1;
            if(check(mid, a, k)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
    
    bool check(int mid, vector<int>&a, int k){
        int n = a.size(), idx = 0;
        
        for(int i=0; i<n; i++){
            if(abs(a[i] - a[idx]) >= mid){
                k--;
                idx = i;
            }
        }
        
        return k<=1;
    }
};