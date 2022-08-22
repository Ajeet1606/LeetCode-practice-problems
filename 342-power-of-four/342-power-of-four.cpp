class Solution {
public:
    bool isPowerOfFour(int n) {
        
        unordered_set<int>s;
        s.insert(1);
        long num = 4;
        while(num < INT_MAX){
            s.insert(num);
            num *= 4;
        }
        
        return s.count(n);
    }
};