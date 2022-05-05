class MyStack {
public:
    queue<int> q;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        queue<int> newqueue  = q;
        vector<int> v;
        queue<int> newqueue2;
        while(!newqueue.empty()){
            v.push_back(newqueue.front());
            newqueue.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            newqueue2.push(v[i]);
        }
        q2=newqueue2;
    }
    
    int pop() {
        queue<int> nq;
        while(!(q.front()==q2.front())){
            nq.push(q.front());
            q.pop();
        }
        int ans = q2.front();
        q=nq;
        q2.pop();
        return ans;
    }
    
    int top() {
        return q2.front();
    }
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */