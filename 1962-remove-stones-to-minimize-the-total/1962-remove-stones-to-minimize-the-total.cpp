class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin() , piles.end(),0);
        
        priority_queue<int> pq;
        
        for(int i =0; i < piles.size(); i++) {
            pq.push(piles[i]);
        }
        int diff = 0;
        while(k--) {
            diff += floor(pq.top()/2);
            int n = pq.top() - floor(pq.top()/2);
            pq.pop();
            pq.push(n);
        }
        
        return sum - diff;
    }
};