class Solution {
public:
    vector<int> minDifference(vector<int>& arr, vector<vector<int>>& queries) {
        int m = arr.size(), n = queries.size();
        vector<int>cnt(101, 0);
        vector<vector<int>>freq(m+1, vector<int>(101, 0));
        
        for(int i=0; i<m; ++i){
            cnt[arr[i]]++;
            //now fill the freq array of the ith position with cnt. 
            for(int j=1; j<101; ++j){
                freq[i+1][j] = cnt[j];
            }
        }
        // for(auto c: freq){
        //     for(auto i: c)
        //         cout<<i<<' ';
        //     cout<<endl;
        // }
        vector<int>ans(n);
        
        for(int idx = 0; idx < n; ++idx){
            int l = queries[idx][0];
            int r = queries[idx][1];
            
            vector<int>temp(101);
            
            for(int i=0; i<101; ++i){
                temp[i] = freq[r+1][i] - freq[l][i];
            }
            
            int a = INT_MAX, prev = -1;
            for(int i=0; i<101; ++i){
                if(temp[i] > 0){
                    if(prev != -1){
                        a = min(a, i - prev);
                    }
                    prev = i;
                }
            }
            
            ans[idx] = a == INT_MAX? -1: a;
        }
        
        return ans;
    }
};