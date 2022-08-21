class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        int slen = stamp.length(), tlen = target.length();
        vector<bool>visited(tlen, false);
        vector<int>result;
        while(count != tlen){
            bool didChange = false;
            for(int i=0; i<=tlen - slen; i++){
                if(!visited[i] and canReplace(target, stamp, i)){
                    count = replace(target, i, slen, count);
                    visited[i] = true;
                    didChange = true;
                    result.push_back(i);
                    if(count == tlen){
                        break;
                    }
                }
            }
            
            if(!didChange){
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool canReplace(string& target, string& stamp, int idx){
        for(int i=0; i<stamp.length(); i++){
            if(target[idx + i] != '?' and target[idx + i] != stamp[i]){
                return false;
            }
        }
        return true;
    }
    
    
    int replace(string& target, int pos, int slen, int count){
        for(int i=0; i<slen; i++){
            if(target[i+pos] != '?'){
                target[i+pos] = '?';
                count++;
            }
        }
        return count;
    }
    
};