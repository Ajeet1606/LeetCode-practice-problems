class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        int count[2], n = sa.size();
        for(auto x: st)
            count[x]++;
        int k;
        for(k = 0; k < n && count[sa[k]]>0; k++)
            count[sa[k]]--;
        return n-k;
    }
};