class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==val)
                cnt++;
        }
        int l=0, r=n-1;
        while(l < r){
            if(arr[l] == val){
                while(arr[r]==val and r>l){
                    r--;
                }
                swap(arr[l], arr[r]);
                r--;
            }
            l++;
        }
        return n-cnt;
    }
};