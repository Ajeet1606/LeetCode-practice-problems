class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        vector<string>ans;
        for(int i=0; i<n; i++){
            int st = i;
            while(i+1<n and a[i+1] == a[i]+1){
                i++;
            }
            string s;
            s += to_string(a[st]);
            if(st != i){
                s += "->";
                s += to_string(a[i]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};