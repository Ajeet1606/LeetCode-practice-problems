class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>a(26);
        int n = s.length();
        for(int i = 0; i < n; i++){
            a[s[i]-'a']++;
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(a[s[i]-'a']==1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};