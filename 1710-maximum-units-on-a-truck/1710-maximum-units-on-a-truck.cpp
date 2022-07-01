class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int>arr(1001, 0);
        //make an array of 1000 size and every idx represents the unit given and its value shows the number of boxes it has corresponding to a unit.
        for(auto a: boxTypes){
            arr[a[1]] += a[0];
        }
        
        int answer = 0, cnt = 0;
        for(int i=1000; i>=0; i--){
            if(cnt >= truckSize){
                break;
            }
            if(arr[i] != 0){
                int x = min(truckSize - cnt, arr[i]); 
                answer += x*i;
                cnt += x;
            }
        }
        return answer;
    }
};