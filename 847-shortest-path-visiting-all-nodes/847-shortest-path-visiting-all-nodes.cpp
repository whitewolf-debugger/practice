class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1)return 0;
        int n = graph.size();
        int endingMask = (1<<n)-1;
        vector<vector<bool>> seen(n,vector<bool>(endingMask,false));
        queue<pair<int,int>> pendingNodes;
        for(int i=0;i<n;i++){
            pendingNodes.push({i,1<<i});
            seen[i][1<<i]=true;
        }
        int steps =0;
        while(!pendingNodes.empty()){
            queue<pair<int,int>> q;
            int size = pendingNodes.size();
            while(size--){
                pair<int,int> front = pendingNodes.front();
                int node = front.first;
                int mask = front.second;
                pendingNodes.pop();
                for(int neighbor : graph[node]){
                    int nextMask = mask | (1 << neighbor);
                     if (nextMask == endingMask) {
                        return 1 + steps;
                    }
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        q.push({neighbor,nextMask});
                    }
                }
            }
            steps++;
            pendingNodes=q;
        }
        return -1;
    }
};