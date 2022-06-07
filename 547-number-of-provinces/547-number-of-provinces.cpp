class Solution {
public:
    void search(vector<vector<int>>& isConnected,int sv,vector<bool>& seen){
        queue<int> pendingNodes;
        pendingNodes.push(sv);
        seen[sv] = true;
        while(!pendingNodes.empty()){
            int front = pendingNodes.front();
            pendingNodes.pop();
            for(int i=0;i<isConnected.size();i++){
                if(front != i && !seen[i] && isConnected[front][i]==1){
                    seen[i] = true;
                    pendingNodes.push(i);
                }
            }
        }
    }
    int BFS(vector<vector<int>>& isConnected,int n){
        vector<bool> seen(n,false);
        int count =0;
        for(int i=0;i<n;i++){
            if(!seen[i]){
                search(isConnected,i,seen);
                count++;
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        return BFS(isConnected,n);
    }
};