class Solution {
public:
    //graph bfs traversal
    void search(vector<vector<int>>& isConnected,int sv,vector<bool>& seen){
        queue<int> pendingNodes;
        pendingNodes.push(sv);
        seen[sv] = true;
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            for(int i=0;i<isConnected.size();i++){
                //if its not 1,1 position means pointing itself and it is unvisited also front has edge with i 
                if(front != i && !seen[i] && isConnected[front][i]==1){
                    //mark it as seen 
                    seen[i] = true;
                    //push in pendingNodes and discover all paths 
                    pendingNodes.push(i);
                }
            }
        }
    }
    int BFS(vector<vector<int>>& isConnected,int n){
        vector<bool> seen(n,false);
        int count =0;
        //cont number of disconnected nodes
        for(int i=0;i<n;i++){
            if(!seen[i]){
                //discover all the nodes connected to current non traversed node
                search(isConnected,i,seen);
                count++;
            }
        }                                                                      
        //return total disconected node
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //ans is returned by BFS function which we return to main
        return BFS(isConnected,n);
    }
};