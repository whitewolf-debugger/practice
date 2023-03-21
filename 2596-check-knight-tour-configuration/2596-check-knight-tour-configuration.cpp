class Solution {
public:
    //do bfs and return true once we reach the n*n - 1 else return false if we come out of bfs 
    bool checkValidGrid(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int last = (ROWS*ROWS) -1;
        if(grid[0][0] != 0) return false;
        vector<pair<int, int>> dirs = {{-2,-1}, {-2,1}, {-1,2}, {1,2},{2,1}, {2, -1}, {1,-2},{-1,-2}};
        queue<vector<int>> q;
        q.push({0,0,0});
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int r = curr[0];
            int c = curr[1];
            int d = curr[2];
            int next = d + 1;
            if(d== last) return true;
            for(auto & dir: dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr < ROWS && nc < COLS && nr >= 0 && nc >= 0 && grid[nr][nc] == next) {
                    q.push({nr,nc,next});
                }
            }
            
        }
        return false;
        
    }
};