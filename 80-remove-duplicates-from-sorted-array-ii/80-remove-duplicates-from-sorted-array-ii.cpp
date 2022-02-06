class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            
            if(i+1<n and arr[i]==arr[i+1]){
                int st = i+2, j = i+2;
                while(j<n and arr[j] == arr[i+1]){
                    j++;
                }
                int end = j;
                while(st != end and end < n){
                    swap(arr[st++], arr[end++]);
                }
                n -= end-st;
                i++;
                ans++;
            }
            ans++;
        }
        return ans;
    }
};