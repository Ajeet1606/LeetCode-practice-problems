class Solution {
public:
    string pushDominoes(string str) {
        int n= str.length();
        
        int last;
        //clear ....L in starting
        int i=0, j, k; 
        while(i<n and str[i] == '.') i++;
        if(i>=n) return str;
        last = i;
        if(str[i] == 'L'){
            j = i-1;
            while(j>=0)
                str[j--] = 'L';
        }
        
        //clear R.... in end
        i = n-1;
        while(i>=0 and str[i] == '.') i--;
        if(str[i] == 'R'){
            j = i+1;
            while(j<n)
                str[j++] = 'R';
        }
        
        i = last+1;
        int curr;
        while(i<n){
            if(str[i] == '.'){
                i++; 
                continue;
            }
            curr = i;
            j = last+1, k = curr -1;
            if(str[last] == str[curr]){
                while(j < curr)
                    str[j++] = str[curr];
            }
            else if(str[last] == 'R' and str[curr] == 'L'){
                while(j<k){
                    str[j++] = str[last];
                    str[k--] = str[curr];
                }
            }
            
            last = curr;
            i++;
        }
        
        return str;
    }
};
