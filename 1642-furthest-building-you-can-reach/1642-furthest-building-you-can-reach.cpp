/*
Keep a priority queue of the same size as ladders.
add positive diffs to pq
Once the pq gets bigger than the ladders, pop the top, and add that popped to the "brick sum".
This idea works because we want to use ladders for the largest diffs that we see.
k = number of ladders
Time Comlexity: O(N log k)
Space Complexity: O(k)
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int bricksum =0;
        int n = heights.size();
        for(int i=1;i<heights.size();i++){
            int diff = heights[i]-heights[i-1];
            if(diff<0) diff = 0;
            pq.push(diff);
            //if size of priority queue is more than the number ofladders
            if(pq.size()>ladders){
                //we add the smallest difference to bricksum since ladder has to be used only when there is huge difference 
                bricksum+=pq.top();
                //so we add small difference to bricksum since that has to be covered with the help of bricks
                pq.pop();
            }
            //if the bricksum exceeds total number of brick we have then the i-1 is the last position we can reach
            if(bricksum> bricks){
                return i-1;
            }
        }
        //if we came out of loop means we are at the end so return n -1
        return n-1;
    }
};