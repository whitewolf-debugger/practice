class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS= grid.size();
        int COLS = grid[0].size();
        int total =0;
        vector<pair<int,int>> directions = {{0,-1},{-1,0},{1,0},{0,1}};
        queue<pair<int,int>> pendingNodes;
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2){
                    pendingNodes.push({i,j});
                }
            }
        }
        int minutes =0;
        int count =0;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            count+=size;
            for(int i=0;i<size;i++){
                pair<int,int> front = pendingNodes.front();
                int row= front.first;
                int col=front.second;
                pendingNodes.pop();
                for(auto& dir: directions){
                    int newrow = row + dir.first;
                    int newcol = col + dir.second;
                    if(newrow>=0 && newcol>=0 && newrow<ROWS && newcol < COLS && grid[newrow][newcol]==1){
                        grid[newrow][newcol]=2;
                        pendingNodes.push({newrow,newcol});
                    }
                }
            }
            if(!pendingNodes.empty()) minutes++;
        }
        return (count == total)? minutes:-1;
    }
};