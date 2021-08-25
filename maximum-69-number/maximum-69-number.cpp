class Solution {
public:
    int maximum69Number (int num) {
       int temp = num;
        bool no6 = true;
        int leftMostOrder;
        for(int i = 1; temp > 0; i *= 10)
        {
            if(temp % 10 == 6){
                leftMostOrder = i;
                no6 = false;
            }
             temp /= 10;
        }
        return no6 ? num : num + 3 * leftMostOrder;
    }
};