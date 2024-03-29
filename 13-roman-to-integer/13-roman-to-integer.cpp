class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.length();
        unordered_map<char, int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i=0; i<n; i++){
            if(s[i] == 'I'){
                if(i+1 < n and s[i+1] == 'V'){
                    ans += 4;
                    i++;
                }
                else if(i+1 < n and s[i+1] == 'X'){
                    ans += 9;
                    i++;
                }else{
                    ans +=1;
                }
            }else if(s[i] == 'X'){
                if(i+1 < n and s[i+1] == 'L'){
                    ans += 40;
                    i++;
                }
                else if(i+1 < n and s[i+1] == 'C'){
                    ans += 90;
                    i++;
                }
                else{
                    ans += 10;
                }
            }else if(s[i] == 'C'){
                if(i+1 < n and s[i+1] == 'D'){
                    ans += 400;
                    i++;
                }
                else if(i+1 < n and s[i+1] == 'M'){
                    ans += 900;
                    i++;
                }else{
                    ans += 100;
                }
            }else{
                ans += m[s[i]];
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};