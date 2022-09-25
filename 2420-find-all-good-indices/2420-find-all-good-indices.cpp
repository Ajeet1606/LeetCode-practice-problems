class Solution{
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n= size(a);
        vector<int> dp1(n+1,1),dp2(n+1,1),ans;
        
        for(int i=1;i<n;i++) 
            if(a[i-1]>=a[i]) dp1[i]= dp1[i-1]+1;
        
        for(int i=n-2;i>=0;i--)  
            if(a[i]<=a[i+1]) dp2[i]= dp2[i+1]+1;
        
        for(int i=k;i<n-k;i++) 
            if(dp1[i-1]>=k && dp2[i+1]>=k) ans.push_back(i);
        return ans;
    }
};