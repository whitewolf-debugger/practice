class Solution {
public:
    vector<pair<int , int>> directions = {
            {0,-1},
        {-1,0} , {1,0},
             {0,1}
    };
    int getSize(vector<vector<int>>& grid,int r,int c,int islandKey) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) {
            return 0;
        }
        grid[r][c] = islandKey;
        int count = 1;
        count += getSize(grid,r + 1 ,c,islandKey);
        count += getSize(grid,r - 1 ,c,islandKey);
        count += getSize(grid,r ,c - 1,islandKey);
        count += getSize(grid,r,c + 1,islandKey);
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int ans = 0;
        unordered_map<int , int> islandSizes;
        int islandKeys = 2;

        for(int r = 0; r < ROWS; r++) { 
            for(int c = 0 ; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    int size = getSize(grid,r,c,islandKeys);
                    islandSizes[islandKeys++] = size;
                    //for case there are no 0 
                    ans = max(ans,size);
                }
            }
        }
        for(int r = 0 ; r < ROWS; r++) {
            for(int c = 0 ; c < COLS;c++) {
                if(grid[r][c] == 0) {
                    set<int> nbr;
                    for(auto [dr,dc] : directions) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS) continue;
                        nbr.insert(grid[nr][nc]);
                    }  
                    int currSum = 1;
                    for(auto & color : nbr) {
                        currSum += islandSizes[color];
                    }
                    ans = max(ans,currSum);
                }
            }
        }
        return ans;
    }
};