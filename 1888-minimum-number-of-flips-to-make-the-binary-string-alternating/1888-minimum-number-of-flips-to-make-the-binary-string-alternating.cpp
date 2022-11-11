class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s += s;
        int res = 2*n;
        string s1, s2;
        for(int i=0; i<2*n; ++i){
            if(i%2 == 0){
                s1.push_back('1');
                s2.push_back('0');
            }else{
                s1.push_back('0');
                s2.push_back('1');
            }
        } 
      // cout<<s1;
        int l=0, r=0;
        int cnt1 = 0, cnt2 = 0;
        while(r < 2*n){
            if(s[r] != s1[r]) cnt1++;
            if(s[r] != s2[r]) cnt2++;
            
            if(r-l+1 > n){
                if(s[l] != s1[l]) cnt1--;
                if(s[l] != s2[l]) cnt2--;
                
                l++;
            }
            
            if(r-l+1 == n){
                res = min(res, min(cnt1, cnt2));
            }
            r++;
        }
        
        return res;
    }
};