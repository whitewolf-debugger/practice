class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i, int j,int ROWS, int COLS,vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= ROWS || j >= COLS){
            return INT_MAX;
        }
        if(i == ROWS-1 && j == COLS-1){
            return grid[i][j] <= 0? abs(grid[i][j])+1 : 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int right = dfs(grid,i+1,j,ROWS,COLS,dp);
        int down = dfs(grid,i,j+1,ROWS,COLS,dp);

        int result = min(right, down) - grid[i][j];
        return dp[i][j] = (result <= 0) ? 1 : result;   
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int ROWS =grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS,vector<int>(COLS,-1));
        int ans = dfs(grid,0,0,ROWS,COLS,dp);
        return ans;
    }
};