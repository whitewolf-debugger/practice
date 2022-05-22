class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int>& path,int target,unordered_set<int> seen,int node){
        if(node ==target){
            ans.push_back(path);
            return;
        }
        for(auto x : graph[node]){
            if(seen.find(x)==seen.end()){
                seen.insert(x);
                path.push_back(x);
                dfs(graph,ans,path,target,seen,x);
                seen.erase(x);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;
        vector<int> path;
        path.push_back(0);
        vector<vector<int>> ans;
        unordered_set<int> seen;
        seen.insert(0);
        dfs(graph,ans,path,target,seen,0);
        return ans;
    }
};