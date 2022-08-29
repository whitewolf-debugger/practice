class Solution {
public:
    int dfs(vector<vector<int>> & graph, int node,vector<int> &ans, vector<int> & quiet){
        if(ans[node] == -1){
            ans[node] = node;
            for(auto& nbr : graph[node]){
                int candidate = dfs(graph, nbr, ans, quiet) ;
                if(quiet[candidate] < quiet[ans[node]]){
                    ans[node] = candidate;
                }
            }
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n  = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> ans(n,-1);
        
        //making adjacency list  
        for(auto& rich: richer){
            graph[rich[1]].push_back(rich[0]);
        }
        
        for(int node = 0; node < n; node++){
            dfs(graph,node,ans,quiet);
        }
        
        return ans;
    }
};
/*

     answer[x] = y if y is the least quiet person
     among all people who definitely have equal to or more money than the person x.




*/