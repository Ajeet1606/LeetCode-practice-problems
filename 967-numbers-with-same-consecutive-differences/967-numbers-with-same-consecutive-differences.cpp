class Solution {
public:
    vector<int>ans;
    
    void solve(int i, int n, int k){
        if(n == 0){
            ans.push_back(i);
            return;
        }
        
        //subtract k
        if(i%10 - k >= 0){
            int num = i*10 + (i%10 - k);
            solve(num, n-1, k);
        }
        //add k
        if(i%10 + k <= 9 and (k!=0)){
            int num = i*10 + (i%10 + k);
            solve(num, n-1, k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i<=9; i++){
            solve(i, n-1, k);
        }
        return ans;
    }
};