class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        unordered_set<string> airline;
        for(auto& edge: tickets) {
            adj[edge[0]].insert(edge[1]);

        }
        stack<string> pendingNodes;
        pendingNodes.push("JFK");
        vector<string> ans;
        while(!pendingNodes.empty()) {
            string currNode = pendingNodes.top(); 
            if(adj[currNode].size() == 0) {
                ans.push_back(currNode);
                pendingNodes.pop();
            } else {
                auto to = adj[currNode].begin();
                pendingNodes.push(*to);
                adj[currNode].erase(to);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};