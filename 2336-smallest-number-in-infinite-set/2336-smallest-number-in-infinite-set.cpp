class SmallestInfiniteSet {
public:
    unordered_set<int>popped_elements;
    int mn = 1;
    
    int popSmallest() {
        while(popped_elements.count(mn) != 0){
            mn++;
        }
        popped_elements.insert(mn);
        return mn;
    }
    
    void addBack(int num) {
        if(popped_elements.count(num) != 0){
            popped_elements.erase(num);
        }
        if(num < mn) mn = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */