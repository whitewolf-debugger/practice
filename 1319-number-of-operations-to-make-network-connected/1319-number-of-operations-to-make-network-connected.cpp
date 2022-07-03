class Solution {
public:
    void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj){
        //base case of dfs 
        if(visited[node]) return;
        //mark visited 
        visited[node]=true;
        for(auto x:adj[node]){
            //visit the nodes connected together which are not visited 
            if(!visited[x]){
                dfs(x,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1) return -1;
        //since there are computers numbered from 0 to n-1 so create a vector of size 
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        //create adjacny matrix to make a map 
        for(int i=0;i<edges;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int count =0;
        for(int i=0;i<n;i++){
            //visit unvisited node 
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        //1 is island remaining are seperate nodes so remove 1 island and return the number of disconncted node 
        return count-1;
    }
};