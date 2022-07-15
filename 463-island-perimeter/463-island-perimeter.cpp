class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int ROWS,int COLS){
        // if we are at the perimeter return 1 
        if(i<0 || j<0 || i>=ROWS || j>=COLS || grid[i][j]==0) return 1;
        //if visited it is -1 then return 0
        if(grid[i][j]==-1) return 0;
        //mark visited
        grid[i][j]=-1;
        //return ans after doing 4 direction dfs calls 
        return dfs(grid,i+1,j,ROWS,COLS)+dfs(grid,i-1,j,ROWS,COLS)+dfs(grid,i,j+1,ROWS,COLS)+dfs(grid,i,j-1,ROWS,COLS) ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if that node has 1 it is unvisited 
                if(grid[i][j]==1){
                    //do dfs 
                    ans = dfs(grid,i,j,m,n);
                }
            }
        }
        //ans stores ans 
        return ans;
    }
};