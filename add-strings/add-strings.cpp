class Solution {
public:
    string addStrings(string s1, string s2) {
        string res;
        int i = s1.length()-1, j = s2.length()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0)
                sum += s1[i]-'0';
            if(j>=0)
                sum += s2[j]-'0';
            carry = 0;
            if(sum>9) carry = sum/10, sum %= 10;
            res += to_string(sum);
            i--; j--;
        }
        
        
        reverse(res.begin(), res.end());
        return res;
    }
};