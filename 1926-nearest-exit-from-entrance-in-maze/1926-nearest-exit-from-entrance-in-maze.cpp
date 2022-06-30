class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>> pendingNodes;
        seen[entrance[0]][entrance[1]]=true;
        //pendingNodes is queue which has {row,col,distace};
        pendingNodes.push({entrance[0],entrance[1],0});
        while(!pendingNodes.empty()){
            vector<int> front = pendingNodes.front();
            //bfs step to pop the element from queue
            pendingNodes.pop();
            //store all the row col and distance 
            int row = front[0];
            int col = front[1];
            int dist = front[2];
            if(row == 0 || col ==0 || row == m-1 || col ==n-1){
               if(row==entrance[0] && col==entrance[1]){ /*do nothing if start start is at the boundary*/}
               //return the distance else since we are at the boundary
               else return dist;
            }
            for(auto& dir:directions){
                //check in all 4 directions 
                int i = row+dir.first;
                int j = col+dir.second;
                //if i and j are in the range and we have not seen that index and thare is empty way at that index 
                if(i>=0 && j>=0 && i<m && j<n && !seen[i][j] && maze[i][j]=='.'){
                    //everytime we do dfs with new valid i and j increase the distance 
                    pendingNodes.push({i,j,dist+1});
                    //mark seen at that index as true
                    seen[i][j]=true;
                }
            }
        }
        //if nothing is returned means no exit then return -1
        return -1;
    }
};