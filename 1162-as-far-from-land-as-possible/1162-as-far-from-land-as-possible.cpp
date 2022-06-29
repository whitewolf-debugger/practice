class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int ans =0;
        int n = grid[0].size();
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        //visited helps us to keep the track of unvisited as well as the distance 
        //if visited ==-1 means unvisited
        vector<vector<int>> visited(m,vector<int>(n,-1));
        queue<pair<int,int>> pendingNodes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //put 0 in all the places of visit where there is one it will help us to keep track of distance 
                if(grid[i][j]==1 && visited[i][j]==-1){
                    visited[i][j]=0;
                    //push all the nodes where there are 1 in queue {row,col}
                    pendingNodes.push({i,j});
                }
            }
        }
        //do bs 
        while(!pendingNodes.empty()){
            pair<int,int> front = pendingNodes.front();
            pendingNodes.pop();
            //get row and col from 1st pair at the top in queue pendingNodes
            int row = front.first;
            int col = front.second;
            //travel in all 4 directions 
            for(auto& d : directions){
                // same as up down , left right but  using directions pair 
                int newrow = row + d.first;
                int newcol = col+ d.second;
                //if the index is valid then check whether it is unvisited and that has 0 in the array grid 
                if(newrow>=0 && newcol>=0 && newrow<m && newcol<n && grid[newrow][newcol]==0 && visited[newrow][newcol]==-1){
                    //for every newrow and newcol containing 0 in grid increase +1 distance from previous node 
                    visited[newrow][newcol] = visited[row][col]+1;
                    //update ans 
                    ans = max(ans, visited[newrow][newcol]);
                    //push is queue to do dfs in all 4 directions 
                    pendingNodes.push({newrow,newcol});
                }
            }
        }
        //if ans is 0 return -1 else return ans 
        return ans==0?-1:ans;
    }
};