class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int ROWS =  grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> ans(ROWS,vector<int>(COLS,0));
        int total = ROWS*COLS;
        for(int r=0;r < ROWS; r++){
            for(int c=0; c < COLS;c++){
                int flatI = r*COLS+c;
                int newFlat = (flatI+k)%total;
                int nr = newFlat/COLS;
                int nc = newFlat%COLS;
                ans[nr][nc] = grid[r][c];
            }
        }
        return ans;
    }
};