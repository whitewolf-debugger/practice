class Solution {
    public:
   
    int MOD = 1e9 +7;

    //directions 
    vector<pair<int , int>> directions = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

    //check if it is out of bounds
    bool isOOBS(int ROWS, int COLS, int r , int c) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS) return true;
        return false;
    }

    //finds and return the number of paths if we start from this point 
    long long dp(vector<vector<int>> &grid , vector<vector<bool>> &visited, int r ,int c, int ROWS, int COLS, vector<vector<int>> &memo) {
        if(memo[r][c] != -1) {

            //memoization
            return memo[r][c];
        }
        long long  res = 1;
        
        //calculating the result
        for(auto& dir: directions) {
            int dr = r + dir.first;
            int dc = c + dir.second;
            //check whether out of bounds or visited or increasing 
            if(!isOOBS(ROWS, COLS, dr , dc) && !visited[dr][dc] && grid[r][c] < grid[dr][dc]){
                //add to the result the result of returned and by remaining test cases 
                res = (res + dp(grid, visited, dr,dc,ROWS, COLS, memo))% MOD;
            }
        }

        //return the memoized result
        return memo[r][c] = res;
    }
    

    int countPaths(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();


        //ans array stores the ans 
        long long ans = 0;

        //memoization array 
        vector<vector<int>> memo(ROWS,vector<int>(COLS ,-1));
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        for(int i =0 ; i < ROWS; i++) {
            for(int j =0; j < COLS; j++) {
                //calculate the ans with the dp vector 
                ans = (ans + dp(grid, visited, i, j, ROWS, COLS, memo)) % MOD;
            }
        }

        return ans;
    }
};