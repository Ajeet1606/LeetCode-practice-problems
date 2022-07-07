class Solution
{
    public:
        unordered_map<string, bool>memo;
        bool isInterleave(string s1, string s2, string s3)
        {
            int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
            if (len1 + len2 != len3) return false;
            return fun(s1, s2, s3, len1, len2, len3, 0, 0, 0);
        }
    
        bool fun(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3){
            //base case.
            if(p3 == len3)
                return (p1==len1 and p2==len2)? true: false;
            
            string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
            if(memo.find(key) != memo.end())
                return memo[key];
            
            //s1 is covered
            if(p1==len1){
                return memo[key] = (s2[p2] == s3[p3])? fun(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1): false;
            }
            //s2 is covered
            if(p2==len2){
                return memo[key] = (s1[p1]==s3[p3])? fun(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1): false;
            }
            //none is covered.
            bool one = false, two = false;
            //s1 matches.
            if(s1[p1]==s3[p3]){
                one = fun(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
            }
            // s2 matches.
            if(s2[p2] == s3[p3]){
                two = fun(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
            }
            
            return memo[key] = one or two;
        }
};