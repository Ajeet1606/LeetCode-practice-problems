class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        queue<int>q;
        q.push(0);
        int mxreach = 0;
        while(!q.empty()){
            int cur = q.front();
            if(cur == n-1) return true;
            q.pop();
            for(int j = max(mxreach+1, cur+ minJump); j < min(cur+maxJump+1, n); ++j){
                if(s[j] == '0'){
                    q.push(j);
                }
            }
            mxreach = cur + maxJump;
        }
        return false;
    }
};