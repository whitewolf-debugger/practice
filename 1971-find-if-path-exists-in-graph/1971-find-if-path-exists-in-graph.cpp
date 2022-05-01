class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        visited[source]=1;
        queue<int> pendingNodes;
        pendingNodes.push(source);
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            if(front == destination){
                return true;
            }
            for(int i=0;i<graph[front].size();i++){
                if(visited[graph[front].at(i)] == 0){
                    pendingNodes.push(graph[front].at(i));
                    visited[graph[front].at(i)]=true;
                }
            }
        }
        return false;
    }
};