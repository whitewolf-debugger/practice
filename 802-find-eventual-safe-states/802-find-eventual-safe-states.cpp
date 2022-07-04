class Solution {
public:
    bool dfs(int node,vector<int> &colors,vector<vector<int>>& graph){
        if(colors[node]>0){
            return colors[node] == 2;
        }
        colors[node]=1;
        for(auto x: graph[node]){
            if(colors[x]==1 || !dfs(x,colors,graph)) return false;
        }
        colors[node] =2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfs(i,colors,graph)) ans.push_back(i); 
        }
        return ans;
    }
};