class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int front;
    MyQueue() {
        
    }    
    void push(int x) {
        if(st1.empty()){
            front = x;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    int pop() {
        int result = st1.top();
        st1.pop();
        if(!st1.empty()) {
            front = st1.top();
        }
        return result;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return st2.empty() && st1.empty();
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