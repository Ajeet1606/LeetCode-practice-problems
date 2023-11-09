class Solution {
public:
    int majorityElement(vector<int>& arr) {
//         brute force: take a map, store frequency, return answer. O(N) & O(N);
        
//         better: linear traversal with sorting. O(nlogn).
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        return arr[n/2];
    }
};