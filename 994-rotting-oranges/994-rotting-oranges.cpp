class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int count = 0;
        int total = 0;
        int minutes = 0;
        queue<pair<int , int>> pendingNodes;
        vector<pair<int , int>> directions = {{0 , 1},{1 , 0} , {-1 , 0} ,{0 , -1}};
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        
        for(int i = 0; i < ROWS; i++){
            for(int j =0; j < COLS; j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2){
                    pendingNodes.push({i , j});
                }
            }
        }
        
        while(!pendingNodes.empty()){
            int size  = pendingNodes.size();
            count+=size;
            for(int i = 0; i < size; i++) {
                pair<int , int> top = pendingNodes.front();
                int row = top.first;
                int col = top.second;
                pendingNodes.pop();
                for(auto &dir : directions) {
                    int i = row + dir.first;
                    int j = col + dir.second;
                    if(i<ROWS && j<COLS && i>=0 && j>=0 && !visited[i][j] && grid[i][j]==1) {
                        pendingNodes.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }   
            if(!pendingNodes.empty()) minutes++;
        }
        return (total == count)?minutes:-1;
    }
};