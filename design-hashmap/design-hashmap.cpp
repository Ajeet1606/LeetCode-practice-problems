class MyHashMap {
private:
    vector<vector<int>>a;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i = 0; i < a.size(); i++){
            if(a[i][0]==key){
                a[i][1] = value;
                return;
            }
        }
        vector<int>v{key, value};
        a.push_back(v);
    }
    
    int get(int key) {
        int val = -1;
        for(int i = 0; i < a.size(); i++){
            if(a[i][0]==key){
                val = a[i][1];
                break;
            }
        }
        return val;
    }
    
    void remove(int key) {
        for(int i = 0; i< a.size(); i++){
            if(a[i][0]==key){
                a.erase(a.begin()+i);
                
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */