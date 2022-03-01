class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>a;
        for(int i=0; i<=n; i++){
            int num = i;
            int bits = 0;
            while(num>0){
                if(num&1) bits++;
                num = num>>1;
            }
            a.push_back(bits);
        }
        return a;
    }
};