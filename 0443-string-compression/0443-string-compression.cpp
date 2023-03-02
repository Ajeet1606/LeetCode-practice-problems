class Solution {
public:
    int compress(vector<char>& chars) {
      
        string str;
        for(int i=0; i<chars.size();){
            char cur = chars[i];
            int cnt = 0;
            while(i < chars.size() and chars[i] == cur){
                cnt++;
                i++;
            }
            str += cur;
            if(cnt > 1)
                str += to_string(cnt);
        }
        chars.resize(0);
        for(int i=0; i<str.length(); i++){
            chars.push_back(str[i]);
        }
        
        return chars.size();
    }
};