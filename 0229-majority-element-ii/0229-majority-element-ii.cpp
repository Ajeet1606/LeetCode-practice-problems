class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
//         boyre moore algorithm
        int n = arr.size(), num1= INT_MIN, num2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] == num1){
                cnt1++;
            }else if(arr[i] == num2){
                cnt2++;
            }else if(cnt1 == 0){
                num1 = arr[i];
                cnt1 = 1;
            }else if(cnt2 == 0){
                num2 = arr[i];
                cnt2= 1;
            }else{
                cnt1 -=1, cnt2-=1;
            }
        }
//         verify numbers;
        
        vector<int>ans;
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == num1) cnt1++;
            else if(arr[i] == num2) cnt2++;
        }
        
        if(cnt1 > n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        
        return ans;
    }
};