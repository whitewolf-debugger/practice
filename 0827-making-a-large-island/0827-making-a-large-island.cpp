class Solution {
public:
    //direction traversal
    vector<pair<int , int>> directions = {
            {0,-1},
        {-1,0} , {1,0},
             {0,1}
    };
    //gets the size of the island as well as changes 1 to (diffenent number) rather say changes color of a grp of island 
    int getSize(vector<vector<int>>& grid,int r,int c,int islandKey) {
        //if we are out of bounds or the current grid belongs to different set of island we return 0 since that cannot be part
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) {
            return 0;
        }
        //change the key
        grid[r][c] = islandKey;
        //return the size
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
        //whenever we encounter a group of island we change the color from 1 to 2 or 3 based on islandKeys
        for(int r = 0; r < ROWS; r++) { 
            for(int c = 0 ; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    int size = getSize(grid,r,c,islandKeys);
                    islandSizes[islandKeys++] = size;
                    //for case there are no 0 then the 1 existing island is the solution itself
                    ans = max(ans,size);
                }
            }
        }
        
        //traverse in the island after changing the color
        for(int r = 0 ; r < ROWS; r++) {
            for(int c = 0 ; c < COLS;c++) {
                //whenever we get 0 water
                if(grid[r][c] == 0) {
                    //check the surrounding island with color
                    set<int> nbr;
                    for(auto [dr,dc] : directions) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS) continue;
                        //insert all the neighbouring different island in the set
                        nbr.insert(grid[nr][nc]);
                    }  
                    //if we make the current 0 as 1 then all diff color island will merge their size + 1 is new island
                    int currSum = 1;
                    //1 for the 0 which has been changed to 1 
                    for(auto & color : nbr) {
                        //add the size of all the neighbouring island groups we have colored differently 
                        currSum += islandSizes[color];
                    }
                    //ans is max of the groups after changing every 0 to 1 and mergining different grps since we can do 0 to 1 once 
                    ans = max(ans,currSum);
                }
            }
        }
        return ans;
    }
};