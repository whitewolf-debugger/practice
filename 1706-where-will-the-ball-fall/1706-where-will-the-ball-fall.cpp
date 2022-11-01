class Solution {
public:
    int helper(vector<vector<int>> &grid,int row,int col,int ROWS,int COLS) {
        //base case of the current row exceeds the max row size then the ball has escaped so we return the column 
        if(row >= ROWS) return col;
        //get the next Column 
        int nextColumn = col + grid[row][col];
        //if nextColumn is exceeding the walls means the ball is trapped 
        if(nextColumn < 0 || nextColumn >= COLS) return -1;
        //if there is a v shape where grid[row][col] = 1 and grid[row][nextColumn] = -1
        if((grid[row][col] ==1 &&  grid[row][nextColumn] == -1) || (grid[row][col] == -1 &&  grid[row][nextColumn] == 1))return -1;
        return helper(grid,row+1,nextColumn,ROWS,COLS);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        //row size 
        int ROWS = grid.size();
        //column size 
        int COLS = grid[0].size();
        //result array
        vector<int> ans(COLS);
        //run a loop from 1st column to the last
        for(int i =0 ; i < COLS; i++) {
            ans[i] = helper(grid,0,i,ROWS,COLS);
        }
        return ans;
    }
};