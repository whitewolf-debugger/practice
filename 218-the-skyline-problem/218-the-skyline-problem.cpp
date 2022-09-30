class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Iterate over all buildings, for each building i,
        // add (position, i) to 'edges'.
        vector<vector<int>> edges;
        for (int i = 0; i < buildings.size(); ++i){
            edges.push_back({buildings[i][0], buildings[i][2]});
            edges.push_back({buildings[i][1], -buildings[i][2]});
        }
        
        // Sort edges by non-decreasing order.
        sort(edges.begin(), edges.end());
        
        // Initailize twp empty priority queues 'live' and 'past',
        // an empty list 'answer' to store the skyline key points.
        priority_queue<int> live;
        priority_queue<int> past;
        vector<vector<int>> answer;
        
        int idx = 0;

        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges[idx][0];
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges[idx][0] == currX){
                // The height of the current building.
                int height = edges[idx][1];
                
                // If this is a left edge, add `height` to 'live'.
                // Otherwise, add `height` to `past`.
                if (height > 0){
                    live.push(height);
                } else {
                    past.push(-height);
                }
                idx += 1;
            }
            
            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!past.empty() && live.top() == past.top()) {
                live.pop();
                past.pop();
            }
            
            // Get the maximum height from 'live'.
            int currHeight = live.empty() ? 0 : live.top();
            
            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.empty() || answer.back()[1] != currHeight)
                answer.push_back({currX, currHeight});
        }
            
        // Return 'answer' as the skyline.
        return answer;  
    }
};