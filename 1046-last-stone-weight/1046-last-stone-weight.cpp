class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue pq(stones.begin(),stones.end()); 
        while(pq.size()>1){
            int large = pq.top();
            pq.pop();
            int second_large= pq.top();
            pq.pop();
            int diff = large - second_large;
            if(diff == 0){
                continue;
                
            }
            pq.push(diff);
        }
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
    }
    
};