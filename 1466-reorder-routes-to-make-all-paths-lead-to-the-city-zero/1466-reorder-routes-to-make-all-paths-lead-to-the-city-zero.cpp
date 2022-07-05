class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> seen(n,false);
        set<pair<int,int>> visited;
        int total  =0;
        for(auto& connection: connections){
            int a = connection[0];
            int b = connection[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            visited.insert({a,b});
        }
        queue<int> pendingNodes;
        pendingNodes.push(0);
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            if(!seen[front]){
                seen[front] = true;
                for(int i=0;i<adj[front].size();i++){
                    pendingNodes.push(adj[front][i]);
                    if(!seen[adj[front][i]] && visited.find({front,adj[front][i]})!=visited.end()){
                        total++;
                    }
                }
            }
        }
        return total;
    }
};