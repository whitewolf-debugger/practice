class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int ROWS,int COLS){
        if(i<0 || j<0 || i>=ROWS || j>=COLS || grid[i][j]==0) return 1;
        if(grid[i][j]==-1) return 0;
        grid[i][j]=-1;
        return dfs(grid,i+1,j,ROWS,COLS)+dfs(grid,i-1,j,ROWS,COLS)+dfs(grid,i,j+1,ROWS,COLS)+dfs(grid,i,j-1,ROWS,COLS) ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans = dfs(grid,i,j,m,n);
                }
            }
        }
        return ans;
    }
};