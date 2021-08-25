class Solution {
public:
    
    bool isSelfDividing(int n){
        int num = n;
        bool ans = true;
        while(n!=0){
            int x = n % 10;
            if(x== 0 || num % x != 0){
                ans = false;
                break;
            }
            n /= 10;
        }
        return ans;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i))
                ans.push_back(i);
        }
        return ans;
    }
};