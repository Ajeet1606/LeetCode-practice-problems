class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> arr;
       
        for(auto& x: ops){
            
            if(x == "D")
            {
                int val = arr.top();
                arr.push(2*val);
            }else if(x == "C")
                arr.pop();
            else if(x == "+")
            {
                int v1 = arr.top();
                arr.pop();
                int v2 = arr.top();
                arr.push(v1);
                arr.push(v1+v2);
            }
            else{
                arr.push(stoi(x));
            }
             
        }
        int sum = 0;
        while(!arr.empty()){
            sum += arr.top();
            arr.pop();
        }
        return sum;
    }
};