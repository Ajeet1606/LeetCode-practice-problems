struct Node{
        const string &word;
        int index;
        Node(const string &word, int index): word(word), index(index) {}
    };


class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node>buckets[26];
        for(auto& word: words){
            char startingChar = word[0];
            buckets[startingChar - 'a'].emplace_back(word, 0);
        }
        
        int ans = 0;
        for(auto c: s){
            auto currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            
            for(auto &node: currBucket){
                ++node.index;
                if(node.index == node.word.size())
                    ++ans;
                else
                    buckets[node.word[node.index] - 'a'].push_back(node);
            }
        }
        return ans;
    }
};