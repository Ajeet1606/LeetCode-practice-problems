class Solution {
public:
    
    string getBinary(int num){
        string ans = "00000000";
        int i=7;
        while(i>=0){
            char c = (num%2) + '0';
            ans[i--] = c;
            num /= 2;
        }
        return ans;
    }
    
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        //vector<string>v(n);
        
        // for(int i=0; i<n; i++){
        //     int num = data[i];
        //     v[i] = getBinary(num);
        //     //cout<<v[i]<<" ";
        // }
        bool flag = true;
        //check for UTF-8 validation
        for(int i=0; i<n; i++){
            //get starting string
            string str = getBinary(data[i]);
            
            //find count bit chars
            int ones = 0, j=0;
            while(j<8 and str[j++] == '1') ones++;
            
            //it's 'ones' bytes character 
            if(j >= 8 or ones == 1 or ones > 4 or ones-1 + i >= n){
                flag = false;
                break;
            }
            while(ones > 1){
                string s = getBinary(data[++i]);
                if(s[0] != '1' or s[1] != '0') break;
                ones--;
            }
            if(ones > 1){
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};








