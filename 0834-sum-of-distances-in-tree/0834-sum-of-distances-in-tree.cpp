class Solution {
    //doing this dfs to get get the actual ans 
    void dfs2(int n, vector<vector<int>> &adj, vector<int> &count, vector<int> &ans, int node, int parent) {
        for(auto& child: adj[node]) {
            if(child != parent) {
                //update the ans as we go down by attaching the parent and child nodes 
                ans[child] = ans[node] - count[child] + (n - count[child]) ; 

                //we are actually updating the sum of distances since distance from neighbour and its children were not there 
                dfs2(n , adj, count, ans, child, node);
            }
        }
    }

    void dfs1(vector<vector<int>> &adj, vector<int> &count, vector<int> &ans, int node, int parent) {
        for(auto& child: adj[node]){
            if(child != parent) {
                dfs1(adj,count,ans,child, node);
                //updating the count ans ans as we go up but we didnot make final ans 
                //current ans has dist from childrens but distance from neigbhour and its childrens are not their
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //stores ans for each children
        vector<int> ans(n);
        
        //counts the number of child from each 
        vector<int> count(n , 1);

        vector<vector<int>> adj(n);

        //make the adjacency vector which has all the edges 
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs1(adj, count, ans, 0, -1);
        dfs2(n, adj, count, ans, 0, -1);

        //return the ans
        return ans;
    }
};