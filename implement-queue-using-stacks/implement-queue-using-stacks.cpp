class MyQueue {
private:
	std::stack<int> helper, nums;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!nums.empty()) {
			helper.push(nums.top());
			nums.pop();
		}
		nums.push(x);
		while (!helper.empty()) {
			nums.push(helper.top());
			helper.pop();
		}
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = nums.top();
        nums.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return nums.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */