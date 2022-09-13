class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int ones = 0;
        int mask1 = 1<<7;   //10000000
        int mask2 = 1<<6;   // 1000000
        
        for(int i=0; i<data.size(); i++){
            if(ones == 0){
                int mask = 1 << 7;
                while((mask & data[i]) != 0){
                    ones++;
                    mask = mask >> 1;
                }
                
                if(ones == 0) continue;
                
                if(ones > 4 or ones == 1) return false;
            }
            else{
                if(!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)){
                    return false;
                }
            }
            ones--;
        }
        
        return ones == 0;
    }
};