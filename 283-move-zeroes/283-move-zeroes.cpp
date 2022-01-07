class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int cnt = 0, n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[cnt] == 0 and arr[i]!=0){
                swap(arr[cnt++], arr[i]);
            }
            if(arr[cnt]!=0) cnt++;
        }
    }
};