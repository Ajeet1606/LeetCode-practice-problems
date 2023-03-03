class Solution {
public:
    int strStr(string hay, string needle) {
        int l1 = hay.length(), l2 = needle.length();
        
        for(int i=0; i < l1; i++){
            int j = 0, k = i;
            while(j < l2 and k < l1 and hay[k] == needle[j]){
                k++;
                j++;
            }
            if(j == l2){
                return i;
            }
        }
        return -1;
    }
};