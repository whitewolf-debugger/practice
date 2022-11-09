class StockSpanner {
public:
    stack<vector<int>> stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top()[0] <= price) {
            ans += stack.top()[1];
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */