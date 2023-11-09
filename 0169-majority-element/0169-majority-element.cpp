class Solution {
public:
    int majorityElement(vector<int>& arr) {
//         brute force: take a map, store frequency, return answer. O(N) & O(N);
        
//         better: linear traversal with sorting. O(nlogn).
//         boyre moore: O(n)
        int n = arr.size(), ans = arr[0], cnt = 1;
        
        for(int i = 1; i<n; i++){
            if(cnt == 0){
                ans = arr[i];
                cnt=1;
            }else if(arr[i] == ans){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ans;
    }
};