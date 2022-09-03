class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans = {1,2,3,4,5,6,7,8,9};
        for(int i=1; i<n; i++){
            vector<int>curr;
            for(auto a: ans){
                int last_digit = a%10;
                if(last_digit - k >= 0){
                    curr.push_back(a*10 + last_digit-k);
                }
                if(last_digit + k <= 9 and k != 0){
                    curr.push_back(a*10 + last_digit+k);
                }
            }
            ans = curr;
        }
        return ans;
    }
};