class Solution {
public:
    
    //xor(n) = n%4==1? 1: 0
    
    //perm =  a1,  a2,   a3,   a4,   a5
    //encode= a1^a2, a2^a3, a3^a4, a4^a5
    //iterating encode array, we get, a1^a2, a1^a3, a1^a4, a1^a5 -> x1
    //find xor(n) -> x2
    //now, x1^x2 = a1; since n is odd, a1 remains.
    
    vector<int> decode(vector<int>& A) {
        int n = A.size() + 1, a1 = A[0], running = A[0];
        for (int i = 1; i < n-1; ++i) {
            running = running ^ A[i];
            a1 = a1^ running;
        }
        
        int xorn = n%4 == 1? 1: 0;
        a1 = a1 ^ xorn;
        
        vector<int> res(n);
        res[0] = a1;
        for (int i=0; i<n-1; i++) {
            res[i+1] = res[i] ^ A[i];
        }
        return res;
    }
};