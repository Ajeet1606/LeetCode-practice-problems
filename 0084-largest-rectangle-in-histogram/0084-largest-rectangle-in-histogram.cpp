class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int>s;
        vector<int>leftSmall(n, 0), rightSmall(n, 0);
        
        //generate leftSmaller for all elements.
        for(int i=0; i<n; i++){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            
            if(s.empty()) leftSmall[i] = 0;
            else leftSmall[i] = s.top()+1;
            
            s.push(i);
        }
        
        //free stack for reuse.
        while(!s.empty()) s.pop();
        
        //generate rightSmaller for all.
        for(int i=n-1; i>=0; --i){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = s.top()-1;
            
            s.push(i);
        }
        
        //calculate final
        for(int i=0; i<n; i++){
            ans = max(ans, (rightSmall[i] - leftSmall[i] +1)*heights[i]);
        }
        
        return ans;
    }
};