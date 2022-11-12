class MedianFinder {
public:
    priority_queue<int> firstQueue;
    priority_queue<int , vector<int>,greater<int>> secondQueue;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(firstQueue.empty() || firstQueue.top() > num) {
            firstQueue.push(num);
        } else {
            secondQueue.push(num);
        }
        
        if(firstQueue.size() > (secondQueue.size() + 1)) {
            secondQueue.push(firstQueue.top());
            firstQueue.pop();
        } else if(secondQueue.size() > (firstQueue.size() + 1)) {
            firstQueue.push(secondQueue.top());
            secondQueue.pop();
        }
    }
    
    double findMedian() {
        double ans = 0;
        if(firstQueue.size() == 0) {
            return ans;  
        }  else {
            if(firstQueue.size() > secondQueue.size()) {
                ans =  firstQueue.top();
            } else if(firstQueue.size() < secondQueue.size()) {
                ans =  secondQueue.top();
            } else {
                ans =  (firstQueue.top() + secondQueue.top()) / 2.0;
            }
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */