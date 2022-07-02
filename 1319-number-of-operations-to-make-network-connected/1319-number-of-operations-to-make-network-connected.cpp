class Solution {
public:
    void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj){
        if(visited[node]) return;
        visited[node]=true;
        for(auto x:adj[node]){
            if(!visited[x]){
                dfs(x,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1) return -1;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count-1;
    }
};