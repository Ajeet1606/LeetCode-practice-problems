class Solution {
public:
    string pushDominoes(string str) {
        int n= str.length();
        //adding 'L' and 'R' to corners to make it easier
        str = 'L' + str + 'R';
        //last will denote the position of L/R we had last time
        int last = 0;
        int i=0, j, k; 
        
        i = last+1;
        int curr;
        while(i<n+2){
            if(str[i] == '.'){  //skip '.'
                i++; 
                continue;
            }
            //now we've to operate on last to curr
            curr = i;
            j = last+1, k = curr -1;
            //both are equal, fill the same 
            if(str[last] == str[curr]){
                while(j < curr)
                    str[j++] = str[curr];
            }
            //R...L combination 
            else if(str[last] == 'R' and str[curr] == 'L'){
                while(j<k){
                    str[j++] = str[last];
                    str[k--] = str[curr];
                }
            }
            //update last
            last = curr;
            i++;
        }
        //skip 1 and n+1 index.
        return str.substr(1, n);
    }
};