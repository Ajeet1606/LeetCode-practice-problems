class Solution {
public:
    
    //xor(n) = n%4==1? 1: 0
    
    //perm = a1, a2, a3, a4, a5
    //encode= a1^a2, a2^a3, a3^a4, a4^a5
    //iterating encode array, we get, a1^a2, a1^a3, a1^a4, a1^a5 -> x1
    //find xor(n) -> x2
    //now, x1^x2 = a1; since n is odd, a1 remains.
    
    vector<int> decode(vector<int>& A) {
        int n = A.size() + 1, a = 0;
        for (int i = 0; i <= n; ++i) {
            a ^= i;
            if (i < n && i % 2 == 1) {
                a ^= A[i];
            }
        }
        vector<int> res = {a};
        for (int a: A) {
            res.push_back(res.back() ^ a);
        }
        return res;
    }
};