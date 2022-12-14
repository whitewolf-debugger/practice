class Solution {
public:
    long long mod = 1e9+7;
    int dp(vector<vector<int>> &grid,vector<vector<bool>> &visited,int r,int c,int ROWS,int COLS,long long sum,int k,vector<vector<vector<int>>>& cache){
        if(r >= ROWS || c >= COLS) return 0;
        if(r == ROWS-1 && c== COLS-1){
            sum += grid[r][c]%mod;
            if(sum % k ==0){
                return 1;
            }
            return 0;
        }
        if(cache[r][c][sum%k] != -1) return cache[r][c][sum%k];
        int right = dp(grid,visited,r,c + 1,ROWS,COLS,sum+grid[r][c],k,cache)%mod;
        int down = dp(grid,visited,r + 1,c,ROWS,COLS,sum+grid[r][c],k,cache)%mod;
        return cache[r][c][sum%k] = (right + down)%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        long long ans = 0;
        int ROWS =  grid.size();
        int COLS = grid[0].size();
        vector<vector<vector<int>>> cache(ROWS,vector<vector<int>>(COLS,vector<int>(k,-1)));
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        ans = dp(grid,visited,0,0,ROWS,COLS,0,k,cache);
        return ans;
    }
};