class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j=0;
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() and j<n and s.top() == popped[j]){
                s.pop();
                j++;
            }
            s.push(pushed[i]);
            
        }
        while(!s.empty() and j<n and s.top() == popped[j]){
            s.pop();
            j++;
        }
        
        return (s.empty() and j ==n);
    }
};