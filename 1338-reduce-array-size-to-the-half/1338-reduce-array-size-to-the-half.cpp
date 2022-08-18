class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int freq[100001] = {0};
        for(auto a: arr){
            freq[a]++;
        }
        
        int bucket[100001] = {0};
        for(int i=1; i<100001; i++){
            if(freq[i])
                bucket[freq[i]]++;
        }
        
        int ans = 0, half = n/2;
        for(int i= 100000; half > 0; i--){
            while(bucket[i] and half>0){
                half -= i;
                bucket[i]--;
                ans++;
            }
        }
        
        return ans;
    }
};