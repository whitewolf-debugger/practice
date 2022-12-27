class Solution {
public:
    void search(vector<vector<int>> &adj ,int n, vector<bool> &visited, int node) {
        queue<int>pendingNodes;
        pendingNodes.push(node);
        visited[node] = true;
        while(!pendingNodes.empty()) {
            int currNode = pendingNodes.front();
            pendingNodes.pop();

            for(auto &nbr : adj[currNode]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    pendingNodes.push(nbr);
                }
            }
        }
    }
     int BFS(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count  =0;
        vector<bool> visited(n, false);
        for(int i =0; i < n; i++) {
            if(!visited[i]) {
                search(adj, n, visited, i);
                count ++;
            }
        }

        return count;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = BFS(n, edges);

        return ans;
    }
};