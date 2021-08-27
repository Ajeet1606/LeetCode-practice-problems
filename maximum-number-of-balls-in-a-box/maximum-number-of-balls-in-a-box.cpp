class Solution {
public:
    
    int sumOfDigits(int n){
        int sum = 0;
        while(n!=0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int countBalls(int low, int high) {
        unordered_map<int, int>map;
        for(int i = low; i <= high; i++){
            int digits = sumOfDigits(i);
            map[digits]++;
        }
        int ans = 0;
        for(auto x: map){
            if(x.second > ans)
                ans = x.second;
        }
        return ans;
    }
};