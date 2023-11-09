class Solution {
public:
    int majorityElement(vector<int>& arr) {
//         brute force: take a map, store frequency, return answer. O(N) & O(N);
        
//         better: linear traversal with sorting. O(nlogn).
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                cnt++;
            }else{
                cnt=1;
            }
            if(cnt > n/2) return arr[i];
        }
        return arr[0];
    }
};