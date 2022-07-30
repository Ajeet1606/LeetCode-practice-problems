class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        
        //combine strings of word2 with their max freq/char.
        vector<int>maxFreq(26, 0);
        //every value of maxFreq will show max count of every char in any string.
        for(auto word2: words2){
            vector<int>w(26, 0);
            for(auto w2: word2){
                w[w2-'a']++;
            }
            
            for(int i=0; i<26; i++){
                maxFreq[i] = max(maxFreq[i], w[i]);
            }
        }
        
        //check if a word from this array passes the maxFreq array.
        for(auto word1: words1){
            vector<int>a1(26, 0);
            for(auto w: word1){
                a1[w-'a']++;
            }
            bool flag = true;
            for(int i=0; i<26; i++){
                if(maxFreq[i] > a1[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word1);
        }
        return ans;
    }
};