class Solution {
public:
    int minimumBuckets(string str) {
        int len = str.length();
        if(len==1){
            if(str[0]=='H')
                return -1;
            else
                return 0;
        }
        int res=0;
        for(int i=0; i<len; i++){
            if(str[i]=='H'){
                if(i+1 < len && str[i+1]=='.'){
                    res++;
                    i+=2;
                    continue;
                }
                if(i-1 >=0 && str[i-1]=='.'){
                    res++;
                    continue;
                }
                return -1;
            }    
        }
        return res;
    }
};