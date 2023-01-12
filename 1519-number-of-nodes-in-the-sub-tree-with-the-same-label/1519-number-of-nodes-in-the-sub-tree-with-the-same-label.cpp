class Solution {
public:
    
    vector<int> DFS(vector<vector<int>> &adj, int n, string &labels,vector<int> &ans, vector<bool> &visited, int node) {
        //get make the letter count vector and mark all of them unvisited 
        vector<int> freqMap(26, 0);
        //set the frequency of the label of current node as 1 
        freqMap[labels[node] - 'a'] = 1;
        //mark the current node as visited 
        visited[node] = true;
        //traverse in neigh bour 
        for(auto& nbr : adj[node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                //as we go down we make freqmap for all the nodes setting the frequency of labels subtrees 
                vector<int> childFreqMap = DFS(adj, n, labels, ans, visited, nbr);
                //as we come up we update the map  by increasing the frequency of label in subtree 
                for(int i = 0; i < 26; i++) {
                    freqMap[i] += childFreqMap[i];
                }
            }
        }
    // ans of current node is the number of same label in subtree i.w freqMap[labels[node] - 'a']
        ans[node] = freqMap[labels[node] - 'a'];
        //return the current freqMap
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