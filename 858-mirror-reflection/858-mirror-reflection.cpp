class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p&1) and !(q&1)){
            p /= 2;
            q /= 2;
        }
        
        if(!(p&1)){
            return 2;
        }
        
        if(!(q&1)){
            return 0;
        }
        
        return 1;
    }
};