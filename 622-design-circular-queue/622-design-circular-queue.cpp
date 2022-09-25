class MyCircularQueue {
public:
    deque<int> dq;
    int size;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(dq.size() >= size){
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(dq.empty()) return false;
        dq.pop_front();
        return true;
    }
    
    int Front() {
        if(dq.empty()) return -1;
        return dq.front();
    }
    
    int Rear() {
        if(dq.empty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        if(dq.empty()) return true;
        return false;
    }
    
    bool isFull() {
        if(dq.size() >= size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */