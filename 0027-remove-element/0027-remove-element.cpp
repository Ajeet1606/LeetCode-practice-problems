class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();
        
        int cnt = 0, lastValIdx = -1;
        for(int i=0; i<n; i++){
            if(arr[i] != val){
                if(lastValIdx > -1){
                    swap(arr[i], arr[lastValIdx]);
                    lastValIdx++;
                }
                cnt++;
            }else{
                if(lastValIdx == -1) lastValIdx = i;
            }
        }
        return cnt;
    }
};