class Solution {
public:
    bool squareIsWhite(string str) {
        int n =str[0] - 96;
        int a = str[1] - 48;
        if((n%2 == 1 && a%2 == 1) || (n%2 == 0 && a%2 == 0))
            return false;
        else
            return true;
    }
};