class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        
        for(int i=0; i<path.length(); i++){
            if(path[i] == '/') continue;
            
            string cur_dir;
            while(i < path.length() and path[i] != '/'){
                cur_dir += path[i];
                i++;
            }
            
            if(cur_dir == ".") continue;
            else if(cur_dir == ".."){
                if(!st.empty()) st.pop();
            }else{
                st.push(cur_dir);
            }
        }
        
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.length() == 0) return "/";
        return res;
    }
};