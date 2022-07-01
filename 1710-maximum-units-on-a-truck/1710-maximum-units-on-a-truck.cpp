class Solution {
public:    
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(arr.begin(), arr.end(), sortFun);
        int n = arr.size();
        int ans = 0, cnt = 0;
        for(auto a: arr){
            if(cnt > truckSize){
                break;
            }
            int x = min(truckSize-cnt, a[0]);
            ans += x*a[1];
            cnt+= x;
        }
        return ans;
    }
             
             
    static bool sortFun(vector<int>&v1, vector<int>&v2){
        return v1[1] > v2[1];
    }
};