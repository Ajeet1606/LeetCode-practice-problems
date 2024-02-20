class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int>s;
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            if(s.empty() or arr[i] > 0){
                s.push(arr[i]);
            }else{
                while(!s.empty() and s.top() > 0 and s.top() < abs(arr[i])){
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(arr[i])){
                    s.pop();
                }else if(s.empty() or s.top() < 0){
                    s.push(arr[i]);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};