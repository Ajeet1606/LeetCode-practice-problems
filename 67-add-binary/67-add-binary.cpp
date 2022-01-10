class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n1 = a.length(), n2 = b.length();
        int carry = 0; 
        int i=n1-1, j=n2-1;
        while(i>=0 or j>=0){
            int x = 0, y = 0;
            if(i>=0){
                if(a[i]=='1') x=1;
            }
            if(j>=0){
                if(b[j]=='1') y=1;
            }
            int sum = x+y+carry;
            if(sum == 0){
                ans += '0'; carry = 0;
            }
            else if(sum == 1){
                ans += '1'; carry = 0;
            }
            else if(sum == 2){
                ans += '0'; carry = 1;
            }
            else if(sum == 3){
                ans += '1'; carry = 1;
            }
            i--; j--;
        }
        if(carry == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};