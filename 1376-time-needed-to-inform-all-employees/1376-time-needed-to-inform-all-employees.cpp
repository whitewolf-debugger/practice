class Solution {
public:
    //we do dfs to find height of Nary tree
    int dfs(int headID,vector<vector<int>> &adj,vector<int> &informtime){
        //do it like maximum height of Nary tree 
        int time =0;
        //travel through all the nodes which are working under head get the max time out 
        for(auto x:adj[headID]){
            time = max(time,dfs(x,adj,informtime));
        }
        //return time + time taken to inform by the head
        return time+informtime[headID];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        //make adjacency list pushing all the worker under manager in vector present at manager[i] of vector<vector>>
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime);
    }
};