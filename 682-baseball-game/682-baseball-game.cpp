class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int n = ops.size();
        for(int i=0; i<n; i++){
            if(ops[i] == "C"){
                s.pop();
            }
            else if(ops[i] == "D"){
                int num = s.top();
                s.push(2*num);
            }
            else if(ops[i] == "+"){
                int num = s.top();
                s.pop();
                num += s.top();
                s.push(num - s.top());
                s.push(num);
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};