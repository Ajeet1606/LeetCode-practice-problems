class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0){
           return false;
        }
        unordered_set<int>s;
        long num = 1;
        while(num < INT_MAX){
            s.insert(num);
            num *= 3;
        }
        
        return s.count(n);
    }
};