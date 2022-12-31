class Solution {
public:

    //helps to travel in 4 directions 
    vector<pair<int , int>> directions ={{0,1},{0,-1},{1,0},{-1,0}};

    //helps to check whether we have eceeded the boundary
    bool isOOBS(int r, int c, int ROWS, int COLS) {
        if(r >= ROWS || c >= COLS || r < 0 || c < 0) return true;
        return false;
    }

    //this helps us to backtrack and reach the ans 
    void getAns(vector<vector<int>> &grid, vector<vector<bool>> &visited, int &ans,  int ROWS, int COLS, int i, int j) {
        //check if we have reached the block we wanted to reach
        if(grid[i][j] == 2) {
            //check if all other place which has 0 are visited or not 
            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    //if it is unvisited then we donot increase the ans 
                    if(grid[r][c] == 0 && !visited[r][c])return;
                }
            }
            //if we came out of loop then bingo!! we have an ans 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
            ans++;
            return;
        }
        
        for(auto & dir : directions) {
            //traverse in all four directions 
            int dr = i + dir.first;
            int dc = j + dir.second;

            //check for whether the generated direction is inbound and not visited and also for obstacles
            if(!isOOBS(dr, dc, ROWS, COLS) && !visited[dr][dc] && grid[i][j] != -1) {
                //mark the current cell as visited 
                visited[dr][dc] = true;
                //go for the next cell
                getAns(grid, visited, ans,ROWS, COLS, dr, dc);
                //come back and mark the current cell as unvisited and we go for the next cell adjacent to parent cell
                visited[dr][dc] = false;
            }
        }

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        //get the row and column
        int ROWS = grid.size();
        int COLS = grid[0].size();

        //make vector visited to keep track of visited cells in the grid 
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        //ans stores the ans we get from the backtracking 
        int ans = 0;
        //x and y stores the index where we find 1 i.e the start index 
        int x , y;
        //traverse in the grid and check for the start index store it in x and y
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                //once we have reached the starting cell store the index in x and y
                if(grid[i][j] == 1) {
                   x = i;
                   y = j;
                }
            }
        }

        //mark the cell x and y i.e the starting cell as visited 
        visited[x][y] = true;
        //find paths from the current index using getAns function which does backtracking 
        getAns(grid, visited, ans,ROWS, COLS, x, y);

        //return the final ans
        return ans;
    }
};