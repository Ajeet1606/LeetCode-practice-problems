class Solution {
public:
    string minimizeResult(string exp) {
        bool plus = false;
        string a="", b="";
        for(auto ch: exp){
            if(ch == '+'){
                plus = true;
            }
            if(!plus){
                a += ch;
            }
            else{
                b += ch;
            }
        }
        
        int n = a.length(), m = b.length();
        string ans;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            int p1;
            if(i==0){
                p1 = 1;
            }
            else{
                p1 = stoi(a.substr(0, i));
            }
            for(int j=1; j<m; j++){
                int mid = stoi(a.substr(i, n-i)) + stoi(b.substr(0, j+1));
                int p2;
                if(j == m-1){
                    p2=1;
                }
                else{
                    p2 = stoi(b.substr(j+1, m-j-1));
                }
                
                if(p1*mid*p2 < mn){
                    mn = p1*mid*p2;
                    ans = a.substr(0, i) + "(" + a.substr(i, n-i) + b.substr(0, j+1) + ")" + b.substr(j+1, m-j-1);
                    
                }
            }
        }
        return ans;
    }
};