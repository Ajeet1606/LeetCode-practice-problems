class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n = arr.size();
        int answer = 1;
        //handel n =1
        if(n == 1) return 1;
        // dp[i] will store the length of longest wiggle subsequence ending at ith idx.
        vector<int>dp(n);
        dp[0]=1;
        //sign[i] will store the difference sign of last diff ending at ith idx.
        vector<bool>sign(n);
        sign[0] = true;
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(j==0){
                    if(arr[i] != arr[j]){
                        dp[i] = 2;
                        sign[i] = (arr[i]-arr[j] > 0) ? true: false;
                    }
                    else{
                        dp[i] = 1;
                        sign[i] = true;
                    }
                }
                else{
                    if(arr[i] != arr[j]){
                        bool currSign = (arr[i]-arr[j] > 0) ? true: false;
                        if(currSign != sign[j]){
                            dp[i] = dp[j]+1;
                            sign[i] = currSign;
                            break;
                        }   
                    }
                }
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};