class Solution {
public:
    int compress(vector<char>& chars) {
      
        int idx = 0;
        for(int i=0; i<chars.size();){
            char curr = chars[i];
            chars[idx++] = curr;
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
                chars[idx++] = s[j++];
            }
        }
        chars.resize(idx);
        return chars.size();
    }
};