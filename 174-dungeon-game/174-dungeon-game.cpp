class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i, int j,int ROWS, int COLS,vector<vector<int>> &dp){
        //if any how we cross the boundary return INT_MAX
        if(i < 0 || j < 0 || i >= ROWS || j >= COLS){
            return INT_MAX;
        }
        //if we are at the end . the end position might have orbs or demon 
        if(i == ROWS-1 && j == COLS-1){
            return grid[i][j] <= 0? abs(grid[i][j])+1 : 1;
        }
        //memoization step
        if(dp[i][j] != -1) return dp[i][j];
        
        //option 1 go right 
        int right = dfs(grid,i+1,j,ROWS,COLS,dp);
        
        //option 2 go down
        int down = dfs(grid,i,j+1,ROWS,COLS,dp);
        
        //get the result which is minimum of the right and down and then subrtact it with grid[i][j]
        int result = min(right, down) - grid[i][j];
        
        //memoization , it the result is negative means player is dead then return 1 else return the result
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