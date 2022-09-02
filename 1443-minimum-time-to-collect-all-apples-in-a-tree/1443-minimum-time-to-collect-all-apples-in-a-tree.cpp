class Solution {
public:
    
    int dfs(vector<vector<int>> &adjList,int node,vector<bool> &hasApple, vector<bool> &visited){
        visited[node] = true;
        int ans = 0;
        
        for(auto nbr: adjList[node]){
            if(!visited[nbr]){
                ans += dfs(adjList,nbr,hasApple,visited);
            }     
        }
        
        if(hasApple[node] || ans > 0){
            ans += 2;
        }
        
        return ans;
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        
        vector<bool> visited(n,false);
        vector<vector<int>> adjList(n);
            
        for(auto &edge :edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        int ans = dfs(adjList,0,hasApple,visited);
        return ans > 0 ? ans - 2 : ans;
    }
};
/*





*/