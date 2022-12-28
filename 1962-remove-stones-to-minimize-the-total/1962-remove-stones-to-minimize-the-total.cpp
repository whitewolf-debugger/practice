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
/*

    we have to remove  floor(piles[i] / 2) stones from piles k times
    we want to return the minimum possible total number of stones remaining after applying the k operations.
    minimum possile stones we can get by removing stones from maximum sized piles 
    so we use priority queue to get maximum sized pile among the current piles and remove (piles[i] / 2) from that
    we store the number of stones removed in diff
    and ans is the sum without removing - stones removed 
    

*/