class MyStack {
public:
    queue<int>q1, q2;
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int t;
        while(q1.size() > 1){
            t = q1.front();
            q2.push(t);
            q1.pop();
        }
        t = q1.front();
        q1.pop();
        swap(q1, q2);
        return t;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return !q1.size();
    }
};

