class Solution {
public:
    long long countGood(vector<int>& ar, int k) {
        int n = ar.size();
        long long ans = 0, cnt_of_pairs = 0;
        unordered_map<int, int>m;
        
        int st = 0, end = 0;
        while(end < n){
            //new element comes, it create new m[ar[end]] number of pairs.
            cnt_of_pairs += m[ar[end]];
            //update frequency map.
            m[ar[end]]++;
            //when we found a good subarray, we shrink the window.
            while(st < end and cnt_of_pairs >= k){
                //if a[st]....a[end]: st<end<n: is a good subarray, then we have n - end number of good subarrays.
                ans += n - end;
                //now, we remove a[st] from the window.
                m[ar[st]]--;
                //reduce it's contribution from number of pairs.
                cnt_of_pairs -= m[ar[st]];
                st++;
            }
            end++;
        }
        return ans;
    }
};