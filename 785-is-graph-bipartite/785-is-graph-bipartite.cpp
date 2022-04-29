class Solution {
    void dfs(vector<vector<int>>& graph,int x,int color,unordered_map<int,int> &colors,bool &ans){
        if(!ans) return;
        if(colors.find(x)!=colors.end()){
            if(colors[x]!=color){
                ans = false;
            }
            return;
        }
        colors[x]=color;
        auto children = graph[x];
        for(auto node : children){
            dfs(graph,node,color^1,colors,ans);
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        int n=graph.size();
        unordered_map<int,int> colors;
        for(int i=0;i<n;i++){
            if(colors.find(i)==colors.end()){
                dfs(graph,i,0,colors,ans);
                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }
};