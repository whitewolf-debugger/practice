class Solution {
public:
    void dfs(int a,vector<vector<int>> &v,vector<int> &vis){
        
        if(vis[a]) return;
        
        vis[a]=1;
        
        for(auto child:v[a]){
            
            dfs(child,v,vis);
            
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=connections.size();
        
        if(n>edges+1) return -1;
        
        vector<vector<int>> v(n);
        
        for(auto i:connections){
            
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int> vis(n+1,0);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,v,vis);
                cnt++;
            }
        }
        
        return cnt-1;
        
    }
};