class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if(len == 0) return 0;
        vector<int>map(24);
        map['I'-'A'] = 1;
        map['V'-'A'] = 5;
        map['X'-'A'] = 10;
        map['L'-'A'] = 50;
        map['C'-'A'] = 100;
        map['D'-'A'] = 500;
        map['M'-'A'] = 1000;
        
        int ans = map[s[len-1] - 'A'];
        for(int i=len-2; i>=0; i--){
            if(map[s[i] - 'A'] < map[s[i+1] - 'A']){
                ans -= map[s[i] - 'A'];
            }
            else{
                ans += map[s[i] - 'A'];
            }
        }
        return ans;
    }
};