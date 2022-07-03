class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n = arr.size();
        int peak = 1, valley= 1;
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                peak = valley+1;
            }
            else if(arr[i] < arr[i-1]){
                valley = peak+1;
            }
        }
        return max(peak, valley);
    }
};