class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size-1;
        int carry = 1;
        while(i>=0){
            digits[i]+= carry;
            if(digits[i]==10){
                digits[i]=0, carry = 1;
                i--;
            }else break;
        }if(i<0) digits.push_back(1), reverse(digits.begin(), digits.end());
        return digits;
    }
};