struct TrieNode{
    TrieNode *child[26];
    bool flag;
    
    TrieNode(){
        flag = false;
        
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
};


class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode *cur = root;
        int k=0;
        
        for(int i=0; i<n; i++){
            k = word[i] - 'a';
            if(cur->child[k] == NULL){
                cur->child[k] = new TrieNode();
            }
            cur = cur->child[k];
        }
        cur->flag = true;
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode *cur = root;
        int k=0;
        for(int i=0; i<n; i++){
            k = word[i] - 'a';
            if(cur->child[k] == NULL) return false;
            cur = cur->child[k];
        }
        return cur->flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        int k=0;
        TrieNode *cur = root;
        
        for(int i=0; i<n; i++){
            k = prefix[i] - 'a';
            if(cur->child[k] == NULL) return false;
            cur = cur->child[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */