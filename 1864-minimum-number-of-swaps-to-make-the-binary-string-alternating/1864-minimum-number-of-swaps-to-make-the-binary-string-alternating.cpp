class Solution {
public:
    
    int count(string &s, char c){
        int cnt = 0;
        for(int i=0; i<s.length(); i+=2){
            if(s[i] != c) cnt++;
        }
        return cnt;
    }
    
    int minSwaps(string s) {
        int n = s.length();
        
        int zero = 0, one = 0;
        for(auto c: s){
            if(c == '0') zero++;
            else one++;
        }
        
        if(abs(zero - one)>1) return -1;
        
        if(zero > one) return count(s, '0');
        else if(one > zero) return count(s, '1');
        else return min(count(s, '0'), count(s, '1'));
    }
};