class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        
        for(int i=0, powerOf2 = 1; i<30; i++, powerOf2 <<= 1){
            string s = to_string(powerOf2);
            sort(s.begin(), s.end());
            if(digits == s)
                return true;
        }
               
        return false;
    }
};