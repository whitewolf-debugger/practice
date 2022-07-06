class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        //make sdjacency list 
        for(int i=0;i<arr.size();i++){
            adj[i].push_back(arr[i]);
        }
        //make queue for bfs 
        queue<int> pendingNodes;
        //push the start in pendingNodes
        pendingNodes.push(start);
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            if(arr[front]==0){
                return true;
            }
            //get the new next index push it in pendingNodes if next is within the range 
            int next = front+arr[front];
            if(next>=0 && next<n && !visited[next]){
                visited[next]=true;
                pendingNodes.push(next);
            }
            //get the new next index push it in pendingNodes if next is within the range 
            next = front-arr[front];
            if(next>=0 && next<n && !visited[next]){
                visited[next]=true;
                pendingNodes.push(next);
            }
        }
        return false;
    }
};