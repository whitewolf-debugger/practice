class Solution {
public:
    int helper(vector<vector<int>> &grid,int row,int col,int ROWS,int COLS) {
        if(row >= ROWS) return col;
        int nextColumn = col + grid[row][col];
        if(nextColumn < 0 || nextColumn >= COLS) return -1;
        if(grid[row][col] != grid[row][nextColumn]) return -1;
        return helper(grid,row+1,nextColumn,ROWS,COLS);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<int> ans(COLS);
        for(int i =0 ; i < COLS; i++) {
            ans[i] = helper(grid,0,i,ROWS,COLS);
        }
        return ans;
    }
};