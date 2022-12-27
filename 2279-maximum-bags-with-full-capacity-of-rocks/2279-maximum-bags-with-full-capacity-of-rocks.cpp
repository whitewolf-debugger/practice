class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //get the number of rocks 
        int n = capacity.size();
        //this is to keep track of minimum difference 
        priority_queue<int , vector<int> ,greater<int>> pq;

        //get the required capacity to make the bag full for every rock
        for(int i =0; i < n; i++) {
            int diff =  capacity[i] - rocks[i];
            //push the difference in the min priority queue so that the minimum difference will be at the top
            pq.push(diff);
        }
        //count keeps track of bags which we can fill completely
        int count = 0;

        // while the additional blocks is greater equal to difference at the top we add the additional stone to that bag and increase the bag as we fill the bag with less amount of space left
        while(!pq.empty() && additionalRocks >= pq.top() && additionalRocks > 0) {
            additionalRocks -= pq.top();
            count++;
            pq.pop();
        }
        //return ans
        return count;
    }
};
/*
    capcity
    2   3   4   5

    rocks
    1   2   4   4






*/