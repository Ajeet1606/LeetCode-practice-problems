class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& A) {
        long long even = A[0], odd = 0;
      
        for(int i=1; i<A.size(); ++i){
            long long newEven = max(even, odd + A[i]);
            odd = max(odd, even - A[i]);
            even = newEven;
        }
   
        return max(even, odd);
    }    
};