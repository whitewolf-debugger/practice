class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int row,int col,int ROWS,int COLS,int sum,int &ans){
        if(row>=ROWS || col>=COLS || row<0 || col<0 || visited[row][col] || grid[row][col]==0){
            ans = max(ans,sum);
            return;
        }
        visited[row][col]=true;
        sum+=grid[row][col];
        dfs(grid,visited,row+1,col,ROWS,COLS,sum,ans);
        dfs(grid,visited,row,col+1,ROWS,COLS,sum,ans);
        dfs(grid,visited,row-1,col,ROWS,COLS,sum,ans);
        dfs(grid,visited,row,col-1,ROWS,COLS,sum,ans);
        visited[row][col]=false;
        sum-=grid[row][col];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int ans =0;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]!=0){
                    int sum =0;
                    vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
                    int temp =0;
                    dfs(grid,visited,i,j,ROWS,COLS,sum,temp);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};