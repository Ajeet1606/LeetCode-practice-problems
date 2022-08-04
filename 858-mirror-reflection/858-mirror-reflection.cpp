class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 and q%2==0){
            p = p >> 1;
            q = q >> 1;
        }
        
        if(p%2==0){
            return 2;
        }
        
        if(q%2==0){
            return 0;
        }
        
        return 1;
    }
};