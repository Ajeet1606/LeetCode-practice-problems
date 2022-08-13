class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>map;
        for(auto word: words){
            map[word]++;
        }
        
        vector<int>ans;
        int wordsLen = words.size(), wordLen = words[0].size(), sLen = s.length();
        //cout<<sLen<<endl;
        int strLen = wordsLen*wordLen;
        if(strLen > sLen){
            return {};
        }
        for(int i=0; i<(sLen - strLen + 1); i++){
            //concatenation string will be of length: wordsLen*wordLen
            int startIdx = -1;
            //cout<<"strLen"<<strLen<<" ";
            string str = "";
            bool isOk = true;
            unordered_map<string, int>temp = map;
            //cout<<i<<" ";
            for(int j=i; j<=strLen + i; j++){
                if(str.length() == wordLen){
                    //cout<<str<<" ";
                    if(temp[str] > 0){
                        temp[str]--;
                        str = "";
                        startIdx = startIdx == -1? i: startIdx;
                        //cout<<"idx"<<" "<<startIdx<<" ";
                    }else{
                        isOk = false;
                        break;
                    }
                }
                str += s[j];
                //cout<<str<<" ";
            }
            if(isOk){
               // cout<<"push"<<" "<<startIdx<<" ";
                ans.push_back(startIdx);
            }
           // cout<<endl;
        }
        return ans;
    }
};