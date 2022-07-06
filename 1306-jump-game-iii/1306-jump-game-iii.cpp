class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(int i=0;i<arr.size();i++){
            adj[i].push_back(arr[i]);
        }
        queue<int> pendingNodes;
        pendingNodes.push(start);
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            if(arr[front]==0){
                return true;
            }
            int next = front+arr[front];
            if(next>=0 && next<n && !visited[next]){
                visited[next]=true;
                pendingNodes.push(next);
            }
            next = front-arr[front];
            if(next>=0 && next<n && !visited[next]){
                visited[next]=true;
                pendingNodes.push(next);
            }
        }
        return false;
    }
};