class MinStack {
private:
    vector<int> s1;
    vector<int> s2;
public:
    void push(int x) {
	    s1.push_back(x);
	    if (s2.empty() || x <= getMin())  s2.push_back(x);	    
    }
    void pop() {
	    if (s1[s1.size()-1] == getMin())  s2.pop_back();
	    s1.pop_back();
    }
    int top() {
	    return s1[s1.size()-1];
    }
    int getMin() {
	    return s2[s2.size()-1];
    }
};