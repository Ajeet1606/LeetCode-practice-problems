class Solution {
public:
    
    bool isMatching(char a, char b)
    {
        return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }
    
    bool isValid(string str) {
        stack<char>s;
        for(int i=0; i<str.length(); i++){
            if(str[i]=='(' || str[i]=='{' || str[i]=='[')
                s.push(str[i]);
            else{
                if(s.empty()==true)
                    return false;
                else if(!isMatching(s.top(), str[i]))
                   return false;
                else
                    s.pop();
            }
            
        }
        return s.empty();
        
    }
};