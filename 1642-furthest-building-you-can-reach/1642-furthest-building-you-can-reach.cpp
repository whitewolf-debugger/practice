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
            if(pq.size()>ladders){
                bricksum+=pq.top();
                pq.pop();
            }
            if(bricksum> bricks){
                return i-1;
            }
        }
        return n-1;
    }
};