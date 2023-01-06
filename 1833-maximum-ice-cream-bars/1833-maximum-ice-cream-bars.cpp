class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        //take min priority queue
        priority_queue<int, vector<int> , greater<int>> pq;
        int ans = 0;

        //push all the cost in the priority queue 
        for(int i =0; i < n; i++) {
            pq.push(costs[i]);
        }

        //while the current cost is >= pq.top() increase the number of shops 
        while(!pq.empty() && coins >= pq.top()) {
            int top = pq.top();
            coins -= top;
            ans++;
            pq.pop();
        }

    
        return ans;

    }
};