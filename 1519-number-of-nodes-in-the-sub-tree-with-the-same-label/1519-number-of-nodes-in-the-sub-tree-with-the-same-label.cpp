class Solution {
public:
    
    vector<int> DFS(vector<vector<int>> &adj, int n, string &labels,vector<int> &ans, vector<bool> &visited, int node) {
        vector<int> freqMap(26, 0);
        freqMap[labels[node] - 'a'] = 1;
        visited[node] = true;
        for(auto& nbr : adj[node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                vector<int> childFreqMap = DFS(adj, n, labels, ans, visited, nbr);
                for(int i = 0; i < 26; i++) {
                    freqMap[i] += childFreqMap[i];
                }
            }
        }
        
        ans[node] = freqMap[labels[node] - 'a'];
        
        return freqMap; 
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n);
        vector<bool> visited(n, false);
        DFS(adj,n,labels, ans ,visited,0);

        return ans;
    }
};