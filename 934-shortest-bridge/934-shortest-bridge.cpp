class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int m,int n,vector<pair<int,int>> &coordinates,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=m || j>=n|| grid[i][j]==0 || visited[i][j]) return;
        coordinates.push_back({i,j});
        visited[i][j]=true;
        dfs(grid,i+1,j,m,n,coordinates,visited);
        dfs(grid,i,j+1,m,n,coordinates,visited);
        dfs(grid,i-1,j,m,n,coordinates,visited);
        dfs(grid,i,j-1,m,n,coordinates,visited);
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> first;
        vector<pair<int,int>> second;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                    if(count ==1){
                        dfs(grid,i,j,m,n,first,visited);
                    }
                    else{
                        dfs(grid,i,j,m,n,second,visited);
                    }
                }
            }
        }
        for(int i =0;i<first.size();i++){
            pair<int,int> f = first[i];
            for(int j=0;j<second.size();j++){
                pair<int,int> s = second[j];
                int diff = abs(f.first-s.first)+abs(f.second-s.second)-1;
                ans = min(ans,diff);
            }
        }
        return ans;
    }
};