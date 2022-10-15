class Solution {
public:
    int compress(vector<char>& chars) {
      
        vector<char>ch;
        for(int i=0; i<chars.size();){
            ch.push_back(chars[i]);
            //count consecutive chars
            int cnt = 1, j = i+1;
            while(j < chars.size() and chars[j] == chars[i]){
                j++;
                cnt++;
            }
            i = j;
            if(cnt == 1) continue;
            j = 0;
            string s = to_string(cnt);
            while(j < s.length()){
                ch.push_back(s[j++]);
            }
            
        }
        chars = ch;
        return ch.size();
    }
};