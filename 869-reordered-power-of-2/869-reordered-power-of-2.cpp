class Solution {
public:
    
    vector<int> countDigits(int n){
        vector<int>arr(10);
        while(n){
            arr[n%10]++;
            n /= 10;
        }
        return arr;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int>digits = countDigits(n);
        
        for(int i=0, powerOf2 = 1; i<30; i++, powerOf2 <<= 1){
            if(digits == countDigits(powerOf2))
                return true;
        }
        
        
        return false;
    }
};