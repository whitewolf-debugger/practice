class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> & visited,int i,int j,int ROWS,int COLS,int &area){
        if(i<0 || j<0 || i>=ROWS || j>=COLS || visited[i][j] || grid[i][j]!=1){
            return;
        }
        visited[i][j]=true;
        area++;
        dfs(grid,visited,i+1,j,ROWS,COLS,area);
        dfs(grid,visited,i,j+1,ROWS,COLS,area);
        dfs(grid,visited,i,j-1,ROWS,COLS,area);
        dfs(grid,visited,i-1,j,ROWS,COLS,area);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int area =0;
                    dfs(grid,visited,i,j,m,n,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};