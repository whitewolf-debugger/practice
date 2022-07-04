class Solution {
public:
    int dfs(int headID,vector<vector<int>> &adj,vector<int> &informtime){
        int time =0;
        for(auto x:adj[headID]){
            time = max(time,dfs(x,adj,informtime));
        }
        return time+informtime[headID];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime);
    }
};