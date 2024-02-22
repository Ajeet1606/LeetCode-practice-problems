class LRUCache {
public:
    class node{
        public: 
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    unordered_map<int, node*>mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key) == 1){
            node *resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void deleteNode(node *delNode){
        node *prev = delNode->prev;
        node *next = delNode->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void addNode(node *myNode){
        node *temp = head->next;
        myNode->next = temp;
        temp->prev = myNode;
        head->next = myNode;
        myNode->prev = head;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */