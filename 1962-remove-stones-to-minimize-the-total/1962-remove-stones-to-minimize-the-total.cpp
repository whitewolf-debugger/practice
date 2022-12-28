class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        //get sum of all the stones in piles
        int sum = accumulate(piles.begin() , piles.end(),0);
        
        priority_queue<int> pq;
        //push total stones in each pile in max priority queue 
        for(int i =0; i < piles.size(); i++) {
            pq.push(piles[i]);
        }
        int diff = 0;
        while(k--) {
            //get the number of stones we are removing add to the diff
            diff += floor(pq.top()/2);
            //get the new number of stones in pile after removing  floor(pq.top()/2) stones from it
            int n = pq.top() - floor(pq.top()/2);
            //remove the old count of stones 
            pq.pop();
            //add the current one 
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