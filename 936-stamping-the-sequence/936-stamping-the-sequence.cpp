class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        int slen = stamp.length(), tlen = target.length();
        vector<bool>visited(tlen, false);
        vector<int>result;
        //count stores the cnt of '?' which must be equal to target length if it's possible to create.
        while(count != tlen){
            bool didChange = false;
            for(int i=0; i<=tlen - slen; i++){
                if(!visited[i] and canReplace(target, stamp, i)){
                    //replace a substring of target with '?' which matches stamp.
                    replace(target, i, slen, count);
                    //current 'i' will not be again taken as starting point of any substr.
                    visited[i] = true;
                    //we changed something.
                    didChange = true;
                    //current idx is an answer
                    result.push_back(i);
                    //if all are turned into '?', we're done.
                    if(count == tlen){
                        break;
                    }
                }
            }
            //in whole iteration we didn't change, there's no possibility.
            if(!didChange){
                return {};
            }
        }
        //actual answer will be reverse of result array.
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool canReplace(string& target, string& stamp, int idx){
        for(int i=0; i<stamp.length(); i++){
            //if indexes of both string mismatch and ther're alphabet, we can't replace.
            //if there's '?', there can be anyhting so either it should match or it's '?'
            if(target[idx + i] != '?' and target[idx + i] != stamp[i]){
                return false;
            }
        }
        return true;
    }
    
    
    void replace(string& target, int pos, int slen, int &count){
        for(int i=0; i<slen; i++){
            //we make target values '?' and count the times we changed.
            if(target[i+pos] != '?'){
                target[i+pos] = '?';
                count++;
            }
        }
        //return count;
    }
    
};