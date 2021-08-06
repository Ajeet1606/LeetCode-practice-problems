class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int x = 1;
        for(int i = 0; i < target.size(); i++){
            if(target[i]==x){
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
                i--;
            }
            x++;
        }
        return ans;
    }
};