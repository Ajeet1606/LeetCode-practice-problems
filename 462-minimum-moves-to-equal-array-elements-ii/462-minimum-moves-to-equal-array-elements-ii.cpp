class Solution {
public:
    int minMoves2(vector<int>& arr) {
        int n = arr.size();
        int ans;
        sort(arr.begin(), arr.end());
        
        if(n&1){
            int md = arr[n/2], cost = 0;
            for(int i=0; i<n; i++){
                cost += abs(arr[i]-md);
            }
            ans = cost;
        }
        else{
            int md1= arr[n/2], md2 = arr[n/2-1];
            int cost1=0, cost2=0;
            for(int i=0; i<n; i++){
                cost1 += abs(arr[i]-md1);
                cost2 += abs(arr[i]-md2);
            }
            ans = min(cost1, cost2);
        }
        
        return ans;
    }
};

//[203125577,-349566234,230332704,48321315,66379082,38651685 3,50986744,-250908656,-425653504,-212123143]